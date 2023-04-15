#include <vector>

using namespace std;

class BIT {
    public:
        // O(nlogn) initialization
        BIT(const vector<int>& nums) {
            int size = nums.size();
            bit.resize(size+1); // BIT always start from index 1
            for (int i=0; i<size; i++) {
                update(i, nums[i]);
            }
        }

        // O(n) initialization
        BIT(const vector<int>& nums) {
            int size = nums.size();
            bit.resize(size+1); // BIT always start from index 1

            for (int i=0; i<size; i++) {
                bit[i+1] = nums[i];
            }

            for (int i=1; i<bit.size(); i++) {
                int j = next(i);
                for (j < bit.size()) {
                    bit[j] += bit[i];
                }
            }
        }

        // TC: O(logn) 
        void update(int idx, int delta) {
            idx += 1;
            while (idx < bit.size()) {
                bit[idx] += delta;
                idx = next(idx);
            }
        }

        // TC: O(logn)
        int prefixSum(int idx) {
            int result = 0;
            while (idx > 0) {
                result += bit[idx];
                idx = parent(idx);
            }

            return result;
        }

        // TC: O(logn)
        int rangeSum(int start, int end) {
            return prefixSum(end) - prefixSum(start-1);
        }

        vector<int> bit;    // index always from 1
    private:
        int lowbit(int idx) {
            return idx & -idx;
        }

        int parent(int idx) {
            return idx - lowbit(idx);
        }

        int next(int idx) {
            return idx + lowbit(idx);
        }
};