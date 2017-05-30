template<class T>
struct fenwick {
    int n;
    vector<T> m, mt;
    fenwick(int n):n(n), m(n,0), mt(n,0) {}
    void add_range(int r, T d) {
        if(r < 0) return;
        for (int i = r; i >= 0; i = (i&(i+1)) - 1)
            mt[i] += d;
        for (int i = r|(r+1); i < n; i |= i + 1)
            m[i] += d * (r-(i&(i+1))+1);
    }
    void add_range(int l, int r, T d) {
        add_range(r, d);
        add_range(l-1, -d);
    }
    T query(int r) {
        if(r < 0) return 0;
        T res = 0;
        for (int i = r; i >= 0; i = (i&(i + 1)) - 1)
            res += m[i] + mt[i] * (i-(i&(i + 1)) + 1);
        for (int i = r|(r + 1); i < n; i |= i + 1)
            res += mt[i] * (r-(i&(i + 1)) + 1);
        return res;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
