template<class T>
struct segtree{
    int n;
    vector<T> t;

    segtree(int sz):n(1 << ((int)(log2(sz - 1)) + 1)), t(n + n,0){}

    T combine(T a, T b){
        return a + b;
    }
    void modify(int p, T val, int root, int l, int r){
        if (r - l < 2){
            t[root] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (p < mid){
            modify(p, val, root<<1, l, mid);
        }
        else{
            modify(p, val, root<<1|1, mid, r);
        }
        t[root] = combine(t[root<<1], t[root<<1|1]);
    }
    void modify(int p, T val){
        modify(p, val, 1, 0, n);
    }
    T query(int x, int y, int root, int l, int r){
        if (r <= x || l >= y) return 0;
        if (x <= l && r <= y){
            return t[root];
        }
        int mid = (l + r) >> 1;
        return combine(query(x, y, root<<1, l, mid), query(x, y, root<<1|1, mid, r));
    }
    T query(int x, int y){
        return query(x, y, 1, 0, n);
    }
};
