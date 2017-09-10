struct segtree { //[l;r)
  struct node {
    int l, r, sum = 0;
    node():l(0), r(0), sum(0) {}
  };
  int n;
  vector<node> all;
  vector<int> root;
  int add_node() {
    all.pb(node());
    return all.size() - 1;
  }
  int add_node(node cur) {
    all.pb(cur);
    return all.size() - 1;
  }
  int add_node(int pos) {
    return add_node(all[pos]);
  }
  int copy_root(int p) {
    node cur = all[root[p]];
    int ans = add_node(cur);
    root.pb(ans);
    return ans;
  }
  segtree(int sz):n(1 << ((int)(log2(sz - 1)) + 1)) {
    add_node();
    root.pb(0);
    build(0, 0, n);
  }
  void build(int v, int l, int r) {
    if (r - l <= 1) return;
    int mid = (l + r) >> 1;
    int p;
    p = add_node();
    all[v].l = p;
    p = add_node();
    all[v].r = p;
    build(all[v].l, l, mid);
    build(all[v].r, mid, r);
  }
  int combine(node a, node b) {
    return a.sum + b.sum;
  }
  void modify(int p, int val, int v, int l, int r) {
    if (r - l < 2) {
      all[v].sum += val;
      return;
    }
    int mid = (l + r) >> 1;
    if (p < mid) {
      int cur = add_node(all[v].l);
      all[v].l = cur;
      modify(p, val, all[v].l, l, mid);
    } else {
      int cur = add_node(all[v].r);
      all[v].r = cur;
      modify(p, val, all[v].r, mid, r);
    }
    all[v].sum = combine(all[all[v].l], all[all[v].r]);
  }
  void modify(int state, int p, int val, bool make_new = true) {
    int cur = root[state];
    if (make_new)
      cur = copy_root(state);
    modify(p, val, cur, 0, n);
  }
  int query(int l, int r, int v, int cl, int cr) {
    if (l >= cr || r <= cl) return 0;
    if (l <= cl && r >= cr) {
      return all[v].sum;
    }
    int mid = (cl + cr) >> 1;
    return query(l, r, all[v].r, mid, cr)
          +query(l, r, all[v].l, cl, mid);
  }
  int query(int state, int l, int r) {
    return query(l, r, root[state], 0, n);
  }
  int kth_element(int v1, int v2, int k, int kek = -1){
    int l = 0, r = n;
    while (r - l > 1){
      int mid = (l + r) >> 1;
      if (all[all[v2].l].sum - all[all[v1].l].sum >= k){
        v1 = all[v1].l;
        v2 = all[v2].l;
        r = mid;
      }
      else{
        k -= all[all[v2].l].sum - all[all[v1].l].sum;
        v1 = all[v1].r;
        v2 = all[v2].r;
        l = mid;
      }
    }
    return l;
  }
  int kth_element(int l, int r, int k){
    return kth(root[l], root[r], k);
  }
};
