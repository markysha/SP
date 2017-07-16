// const int mod = 1000000007;

template<typename T>
struct segtree {
  int n;
  vector<T> t;
  vector<T> lazy;
  segtree(int sz):n(1 << ((int)(log2(sz - 1)) + 1)), t(n + n, 1), lazy(n + n, 1){}
  segtree(){}
  void push(int v) {
    if (v < n) {
      t[v<<1] = (1ll * t[v<<1] * lazy[v]) % mod;
      lazy[v<<1] = (1ll * lazy[v<<1] * lazy[v]) % mod;
      //
      t[v<<1|1] = (1ll * t[v<<1|1]* lazy[v]) % mod;
      lazy[v<<1|1] = (1ll * lazy[v<<1|1] * lazy[v]) % mod;
    }
    lazy[v] = 1;
  }
  void update(int l, int r, T val, int v, int cl, int cr) {
    if (l >= cr || r <= cl) return;
    if (cl >= l && cr <= r) {
      t[v] = (1ll * t[v] * val) % mod;
      lazy[v] = (1ll * lazy[v] * val) % mod;
      return;
    }
    int mid = (cl + cr) >> 1;
    push(v);
    update(l, r, val, v<<1, cl, mid);
    update(l, r, val, v<<1|1, mid, cr);
    t[v] = (t[v<<1] + t[v<<1|1]) % mod;
  }
  void update(int l, int r, T val) {
    update(l, r, val, 1, 0, n);
  }
  T query(int l, int r, int v, int cl, int cr){
    if (l >= cr || r <= cl) return 0;
    if (cl >= l && cr <= r) {
      return t[v];
    }
    int mid = (cl + cr) >> 1;
    push(v);
    return (query(l,r,v<<1,cl,mid)+query(l,r,v<<1|1,mid,cr))%mod;
  }
  T query(int l, int r){
    return query(l, r, 1, 0, n);
  }
};
