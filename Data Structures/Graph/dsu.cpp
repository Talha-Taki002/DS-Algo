#include <vector>
#include <numeric>
#include <algorithm>

namespace DisjointSetUnion {
    struct Disjoint_Set_Union {
        int n, compo_cnt, max_size;
        std::vector <int> dsu, size;
    
        Disjoint_Set_Union() {}
        Disjoint_Set_Union(int n) : n(n) {
            compo_cnt = n;
            max_size = 1;
            dsu.resize(n+1); // 1-based. Can also be used as 0-based.
            iota(dsu.begin(), dsu.end(), 0);
            size.assign(n+1, 1);
        }
    
        int Find(int x) { return x == dsu[x]? x : dsu[x] = Find(dsu[x]); }

        void Union(int u, int v) {
            u = Find(u);
            v = Find(v);

            if (u != v) {
                dsu[v] = u;
                size[u] += size[v];
                compo_cnt--;
                max_size = std::max(max_size, size[u]);
            }
        }
    };
}