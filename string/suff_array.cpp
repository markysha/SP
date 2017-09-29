
int BEG = ;
int SIGMA = ;

vector<vector<int>> all;

template<class T>
vector<int> suff_array(T s) {
//  s += BEG - 1;
  int n = s.size();
  vector<int> nc(n), c(n, 0), cnt(n + SIGMA, 0), p(n), np(n);
  for (int i = 0; i < n; i++) cnt[s[i] - BEG + 1]++;
  for (int i = 1; i < cnt.size(); i++) cnt[i] += cnt[i - 1];
  for (int i = 0; i < n; i++) p[--cnt[s[i] - BEG + 1]] = i;
  c[p[0]] = 0;
  int g = 0;
  for (int i = 1; i < n; i++) {
    if (s[p[i]] != s[p[i - 1]]) g++;
    c[p[i]] = g;
  }
//  all.pb(c);
  for (int k = 0; (1 << k) < n + n; k++) {
    for (int i = 0; i < cnt.size(); i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) {
      int v = (p[i] - (1 << k) + n + n) % n;
      np[i] = v;
      cnt[c[v]]++;
    }
    for (int i = 1; i < cnt.size(); i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--) p[--cnt[c[np[i]]]] = np[i];
    int g = 0;
    nc[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      int x = p[i];
      int y = p[i - 1];
      if (!(c[x] == c[y] && c[(x + (1 << k)) % n] == c[(y + (1 << k)) % n])) g++;
      nc[p[i]] = g;
    }
    swap(nc, c);
//    all.pb(c);
  }
//  c.pop_back();
  return c;
}


vector<int> lcp(vector<int> a/*suffix array*/){
  int n = a.size();
  vector<int> ans(n - 1);
  vector<pair<int, int>> pr;
  for (int i = 0; i < a.size(); i++) pr.pb({a[i], i});
  sort(pr.begin(), pr.end());
  for (int i = 0; i < n - 1; i++){
    int x = pr[i].S;
    int y = pr[i + 1].S;
    int& res = ans[i];
    for (int j = all.size() - 1; j >= 0; j--){
      if (all[j][x] == all[j][y]){
        res += (1 << j);
        x = (x + (1 << j)) % n;
        y = (y + (1 << j)) % n;
      }
    }
    res = min(res, n);
//    res = min(res, n - pr[i].S);
//    res = min(res, n - pr[i + 1].S);
  }
  return ans;
}
