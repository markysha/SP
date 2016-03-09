class segtree {
  ///modification on segment , find max
public:
  int n = 0, h = 0;
  vector < int > t;
  vector < int > d;

  segtree (int x) {
    n = x;
    h = 32 - __builtin_clz(n) + 1;
    t.resize(n * 2, 0);
    d.resize(n, 0);
  }
  segtree () {}

  void apply(int p, int value) {
    t[p] += value;
    if (p < n) {
      d[p] += value;
    }
  }

  void build(int p) {
    while (p > 1) {
      p >>= 1;
      t[p] = max(t[p << 1], t[p << 1 | 1]) + d[p];
    }
  }
  void push(int p) {
    for (int s = h; s > 0; s--) {
      int i = p >> s;
      if (d[i] != 0) {
        apply(i << 1, d[i]);
        apply(i << 1 | 1, d[i]);
        d[i] = 0;
      }
    }
  }

  void inc(int l, int r, int value) {
    l += n;
    r += n;
    int l1 = l, r1 = r;
    for (l, r; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, value);
      if (r & 1) apply(--r, value);
    }
    build(l1);
    build(r1 - 1);
  }

  int query(int l, int r) {
    l += n;
    r += n;
    push(l);
    push(r - 1);
    int ans = -2e9;
    for (l, r; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans = max(ans, t[l++]);
      if (r & 1) ans = max(ans, t[--r]);
    }
    return ans;
  }
};
