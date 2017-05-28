template<class T>
struct segtree { //[l;r) 
    int n;
    vector<T> t;
    vector<T> lazy;
    segtree(int sz):n(1 << ((int)(log2(sz - 1)) + 1)), t(n + n,0), lazy(n + n, 0) {}
    void push(int v, int l, int r) {
        if (lazy[v] != 0 && v < n) {
            int mid = (l + r) >> 1;
            t[v<<1] += lazy[v] * (mid - l);
            t[v<<1|1] += lazy[v] * (r - mid);
            lazy[v<<1] += lazy[v];
            lazy[v<<1|1] += lazy[v];
            lazy[v] = 0;
        }
    }
    void modify(int x, int y, T val, int root, int l, int r) {
        if (x >= r || y <= l) return;
        if (x <= l && r <= y) {
            lazy[root] += val;
            t[root] += val * (r - l);
            return;
        }
        push(root, l, r);
        int mid = (l + r) >> 1;
        modify(x, y, val, root<<1, l, mid);
        modify(x, y, val, root<<1|1, mid, r);
        t[root] = t[root<<1] + t[root<<1|1];
    }
    void modify(int x, int y, int val) { 
        modify(x, y, val, 1, 0, n);
    }
    T query(int x, int y, int root, int l, int r) {
        if (x >= r || y <= l) return 0;
        if (x <= l && r <= y) {
            return t[root];
        }
        push(root, l, r);
        int mid = (l + r) >> 1;
        return query(x, y, root<<1, l, mid) + query(x, y, root<<1|1, mid, r);
    }
    T query(int x, int y) {
        return query(x, y, 1, 0, n);
    }
};
