
const int N = 100100;

//int mod[2] = {1000000000 + 9, 1000000000 + 7};
int mod[2] = {888888901, 999988901};
vector<int> st[2];
int add[2] = {449, 37};
const char smallest = 'a';

bool precalc() {
  st[0].resize(N);
  st[0][0] = 1;
  st[1].resize(N);
  st[1][0] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      st[j][i] = (1ll * st[j][i - 1] * add[j]) % mod[j];
    }
  }
  return false;
}

bool precalc_crash = precalc();

template<typename T>
struct super_hash {
  vector<int> a[2];
  super_hash() {}
  super_hash(T s) {
    a[0].resize(s.size());
    a[1].resize(s.size());
    a[0][0] = (s[0] - smallest) + 1;
    a[1][0] = (s[0] - smallest) + 1;
    for (int i = 1; i < s.size(); i++) {
      for (int j = 0; j < 2; j++) {
        a[j][i] = a[j][i - 1];
        a[j][i] = (1ll * a[j][i] + 1ll * st[j][i] * (s[i] - smallest + 1)) % mod[j];
      }
    }
  }
  pair<int, int> get_hash(int l, int r, int p = N - 1) {
    pair<int, int> ans;
    ans.F = a[0][r] - (l == 0 ? 0 : a[0][l - 1]);
    if (ans.F < 0) ans.F += mod[0];
    ans.F = (1ll * ans.F * st[0][p - l]) % mod[0];
    ans.S = a[1][r] - (l == 0 ? 0 : a[1][l - 1]);
    if (ans.S < 0) ans.S += mod[1];
    ans.S = (1ll * ans.S * st[1][p - l]) % mod[1];
    return ans;
  }
};
