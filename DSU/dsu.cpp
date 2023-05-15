#include <vector>
#include <numeric>

using namespace std;

class DSU {
    public:
        DSU(int num) {
            roots.resize(num);

            // initialize each index's root as itself
            for (int i=0; i<num; i++) {
                roots[i] = i;
            }

            // it can use STL instead
            // iota(roots.begin(), roots.end(), 0);
        }

        // find the root index of current index
        int find(int idx) {
            if (roots[idx] == idx) {
                return idx;
            }

            // path reduction
            roots[idx] = find(roots[idx]);
            return roots[idx];
        }

        // join two index together, set their root index as the same
        void join(int lhs, int rhs) {
            int lhs_root = find(lhs);
            int rhs_root = find(rhs);

            if (lhs_root == rhs_root) {
                return;
            }

            // choose minimm as root
            int min_root = min(lhs_root, rhs_root);
            roots[lhs_root] = min_root;
            roots[rhs_root] = min_root;
        }

        vector<int> roots;  // record the root index of current index
};