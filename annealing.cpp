
long double getE() {
    return 0.0;
}

long double getA() {
    return (rand() % 1000) / 1000.0;
}

int main() {
    int rep = 1;

    long double E = getE();
    long double pastE = E;

    while (rep --) {
        long double T = 80.0;
        long double K = 0.997;
        while (T > 1e-5 && E != 0) {
            int m = 70;
            while (m--) {
                /// make new state

                ///
                long double cE = getE();
                long double dE = cE - pE;
                if (dE <= 0 || exp((1.0 * (-dE)) / T) >= getA()) {
                    if (cE < E) {
                        E = cE;
                        bs = s;
                    }
                    pE = cE;
                } else {
                    /// last state = new state
                }
            }
            T *= K;
        }
    }

    return 0;
}
