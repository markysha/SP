template<class T>
struct segtree { //[l;r)
  struct node{
    int len, cnt;
    bool f = false;
    node():len(0), cnt(0), f(false){}
  };
  int n;
  vector<T> t;
  segtree(int sz):n(1 << ((int)(log2(sz - 1)) + 1)), t(n + n){
    build(1, 0, n);
  }
  void build(int v, int l, int r){
    t[v].len = r - l;
    int mid = (l + r) >> 1;
    build(v >> 1, l, mid);
    build(v >> 1|1, mid, r);
  }
  void push(int v) {
    if (t[v].f){
      int to;
      to = v << 1;
      t[to].cnt = t[to].len - t[to].cnt;
      t[to].f ^= 1;
      to = v << 1|1;
      t[to].cnt = t[to].len - t[to].cnt;
      t[to].f ^= 1;
      t[v].f = 0;
    }
  }
  void modify(int x, int y, T val, int root, int l, int r) {
    if (x >= r || y <= l) return;
    if (x <= l && r <= y) {
      t[root].f ^= 1;
      t[root].cnt = t[root].len - t[root].cnt;
      return;
    }
    push(root);
    int mid = (l + r) >> 1;
    modify(x, y, val, root<<1, l, mid);
    modify(x, y, val, root<<1|1, mid, r);
    t[root].cnt = t[root<<1].cnt + t[root<<1|1].cnt;
  }
  void modify(int x, int y, T val) {
    modify(x, y, val, 1, 0, n);
  }
  T query(int x, int y, int root, int l, int r) {
    if (x >= r || y <= l) return 0;
    push(root);
    if (x <= l && r <= y) {
      return t[root].cnt;
    }
    int mid = (l + r) >> 1;
    return query(x, y, root<<1, l, mid) + query(x, y, root<<1|1, mid, r);
  }
  T query(int x, int y) {
    return query(x, y, 1, 0, n);
  }
};
