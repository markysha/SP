unordered_map<long long, long long> Fib;

long long fib(long long n){
    if (n < 2) 
        return 1;
    if (Fib.find(n) != Fib.end()) 
        return Fib[n];
    Fib[n] = (fib((n + 1) / 2) * fib(n / 2) + fib((n - 1) / 2) * fib((n - 2) / 2)) % MOD;
    return Fib[n];
}
