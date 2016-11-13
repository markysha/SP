struct fenwicktree_2{
  vector < vector < int > > t;
  int n;
  int m;

  fenwicktree_2(int x, int y){
    n = x;
    m = y;
    t.resize(n);
    for (int i = 0; i < n; i++)
    	t[i].resize(m, 0);
  }

  fenwicktree_2(int x){
    n = x;
    m = x;
    t.resize(n);
    for (int i = 0; i < n; i++)
      t[i].resize(m, 0);
  }

  int sum(int r1, int r2) {
  	int ans = 0;
  	for (int i = r1; i >= 0; i = (i & (i + 1)) - 1)
  		for (int j = r2; j >= 0; j = (j & (j + 1)) - 1)
  			ans += t[i][j];
  	return ans;
  }

  void inc (int r1, int r2, int delta) {
  	for (int i = r1; i < n; i = (i | (i + 1)))
  		for (int j = r2; j < m; j = (j | (j + 1)))
  			t[i][j] += delta;
  }

  int sum(int l1, int r1, int l2, int r2) {
    return sum(l2, r2) - sum (l2, r1 - 1) - sum(l1 - 1, r2) + sum(l1 - 1, r1 - 1);
  }
};
