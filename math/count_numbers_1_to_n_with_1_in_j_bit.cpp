//int
vector<int> count_1(int n){
    const int kbit = 31;
    vector<int> k1(kbit + 1, 0);
    for (int i = 0; i < kbit; i++) {
        int &ans = k1[i];
        int j = (1 << i);
        if (j & n) {
            ans += 1 + (n & (j - 1));
        }
        int x = n >> (i + 1);
        ans += x * j;
    }
    return k1;
}

//long long
vector<long long> count_1(long long n){
    const int kbit = 63;
    vector<long long> k1(kbit + 1, 0);
    for (int i = 0; i < kbit; i++) {
        long long &ans = k1[i];
        long long j = (1 << i);
        if (j & n) {
            ans += 1 + (n & (j - 1));
        }
        long long x = n >> (i + 1);
        ans += x * j;
    }
    return k1;
}

