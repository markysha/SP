vector < int > Z, P;

for(int i = 1; i < n; i++)
	if(Z[i] > 0)
		for(int j = Z[i] - 1; j >= 0 && !(P[i + j]); j--)
			P[i + j] = j + 1;

///taken from http://codeforces.com/blog/entry/9612
