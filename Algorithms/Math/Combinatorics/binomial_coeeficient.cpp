#include <vector>

namespace PascalsTriangle {
    template <typename T> std::vector <std::vector <T>> Pascal(T N){
        std::vector <std::vector <T>> C;
        C.assign(N+1, std::vector <T> (N+1));
        C[0][0] = 1;

        for (int n = 1; n <= N; ++n) {
            C[n][0] = C[n][n] = 1;
            for (int k = 1; k < n; ++k) {
                C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
            }
        }

        return C;
    }

    template <typename T> std::vector <std::vector <T>> Pascal(T N, T mod) {
        std::vector <std::vector <T>> C;
        C.assign(N+1, std::vector <T> (N+1));
        C[0][0] = 1 % mod;

        for (int n = 1; n <= N; ++n) {
            C[n][0] = C[n][n] = 1;
            for (int k = 1; k < n; ++k) {
                C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % mod;
            }
        }

        return C;
    }
}