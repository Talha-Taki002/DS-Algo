#include <vector>

namespace SieveOfEratosthenes {

    struct Sieve {
        int n;
        std::vector <bool> isPrime;

        Sieve(int n) : n(n) {
            isPrime.assign(n+1, true);
            isPrime[0] = isPrime[1] = false;

            for(int i = 4; i <= n; i += 2) {
                isPrime[i] = false; // a good optimization
            }
            for(int i = 3; i <= n; i += 2) {
                if (isPrime[i] && (long long)i*i <= n) {
                    for(int j = i*i; j <= n; j += (i << 1)) {
                        isPrime[j] = false;
                    }
                }
            }
        }
    };
}

