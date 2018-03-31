template <int N>
struct my_set {
  int n = N;
  array<int, N> t;
  array<int, N> l;
  array<int, N> r;
  void clear() {
    t.fill(0);
    l.fill(-1);
    r.fill(n);
  }
  int find(int x) {
    for (int i = 0; ; i ++) {
      if (x - i < 0) return -1;
      if (t[x - i]) return x - i;
      if (l[x - i] != -1) return l[x - i];
    }
  }
  void insert(int x) {
    if (t[x]) return;
    t[x] = 1;
    for (int i = 0; ; i++) {
      if (x - i >= 0 && t[x - i]) {
        l[x] = x - i;
        if (r[x - i] != N) {
          r[x] = r[x - i];
          l[r[x]] = x;
        }
        r[x - i] = x;
        break;
      }
      if (x + i < n && t[x + i]) {
        r[x] = x + i;
        if (l[x + i] != -1) {
          l[x] = l[x + i];
          r[l[x]] = x;
        }
        l[x + i] = x;
        break;
      }
    }
  }
};

