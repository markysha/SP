struct fenwicktree_1{
  vector < int > t;
  int n;

  fenwicktree(int x){
    n = x;
    t.resize(n, 0);
  }

  int sum (int r) {
    int ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ans += t[r];
    return ans;
  }

  void inc (int i, int delta) {
    for (; i < n; i = (i | (i + 1)))
      t[i] += delta;
  }

  int sum (int l, int r){
    return sum (r) - sum (l - 1);
  }
};
