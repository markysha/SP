struct Fenwick{ ///[l, r)
  vector<int> t;
  int n;
  Fenwick(int x):n(x), t(n, 0) {}
  int query(int r) {
    int ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ans += t[r];
    return ans;
  }
  void modify(int i, int delta) {
    for (; i < n; i = (i | (i + 1)))
      t[i] += delta;
  }
  int query(int l, int r) {
    return query(r - 1) - query(l - 1);
  }
};
