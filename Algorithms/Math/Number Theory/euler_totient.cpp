#include <vector>

namespace EulerTotient {
    template <typename T> T phi(T n) {
        T result = n;
        for (T i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0)
                    n /= i;
                result -= result / i;
            }
        }
        if (n > 1)
            result -= result / n;
        return result;
    }

    template <typename T> std::vector <T> phi_generator(T n) {
        std::vector <T> phi(n+1);
        for (T i = 0; i <= n; i++)
            phi[i] = i;

        for (T i = 2; i <= n; i++) {
            if (phi[i] == i) {
                for (T j = i; j <= n; j += i)
                    phi[j] -= phi[j] / i;
            }
        }

        return phi;
    }
}