int n, k;
vector<vector<int>> g;
vector<int> mt;
vector<char> used;

bool try_kuhn (int v) {
  if (used[v])  return false;
  used[v] = true;
  for (int i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (mt[to] == -1) {
      mt[to] = v;
      return true;
    }
  }
  for (int i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (try_kuhn(mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}

int main() {

  mt.assign(k, -1);
//  used.assign(n, false);
//  for (int v = 0; v < n; ++v) {
//    if (try_kuhn (v)
//        used.assign(n, false);
//  }
  for (int run = 1; run; ) {
    run = 0;
    used.assign(n, false);
    for (int i = 0; i < n; i++)
      if (mt[i] == -1 && dfs(i))
        run = 1;
  }

  for (int i = 0; i < k; ++i)
    if (mt[i] != -1)
      printf ("%d %d\n", mt[i]+1, i+1);
}
