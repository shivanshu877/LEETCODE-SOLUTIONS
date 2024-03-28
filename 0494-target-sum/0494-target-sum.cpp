#include <vector>
#include <algorithm>

class Solution {
    int total;

public:
    int findTargetSumWays(std::vector<int>& nums, int S) {
        total = std::accumulate(nums.begin(), nums.end(), 0);

        std::vector<std::vector<int>> memo(nums.size(), std::vector<int>(2 * total + 1, INT_MIN));

        return calculate(nums, 0, 0, S, memo);
    }

    int calculate(std::vector<int>& nums, int i, int sum, int S, std::vector<std::vector<int>>& memo) {
        if (i == nums.size()) {
            if (sum == S) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (memo[i][sum + total] != INT_MIN) {
                return memo[i][sum + total];
            }
            int add = calculate(nums, i + 1, sum + nums[i], S, memo);
            int subtract = calculate(nums, i + 1, sum - nums[i], S, memo);
            memo[i][sum + total] = add + subtract;
            return memo[i][sum + total];
        }
    }
};
