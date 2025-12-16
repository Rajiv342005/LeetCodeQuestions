#include <vector>
#include <numeric>  // for std::accumulate
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;

        // Check if array is non-decreasing
        auto sortedCheck = [&](const vector<int>& a) {
            for (int i = 1; i < (int)a.size(); i++) {
                if (a[i] < a[i - 1]) return false;
            }
            return true;
        };

        // Simulate until sorted
        while (!sortedCheck(nums)) {
            int n = nums.size();
            int minSum = INT_MAX;
            int removeIndex = -1;

            // Find smallest adjacent pair sum
            for (int i = 0; i + 1 < n; i++) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    removeIndex = i;
                }
            }

            // Replace the left pair with its sum
            nums[removeIndex] = minSum;
            nums.erase(nums.begin() + removeIndex + 1);

            ans++;
        }
        return ans;
    }
};
