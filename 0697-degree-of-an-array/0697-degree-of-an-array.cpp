
class Solution {
public:
    int findShortestSubArray(std::vector<int>& nums) {
        std::unordered_map<int, int> left, right, count;

        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            if (left.find(x) == left.end()) {
                left[x] = i;
            }
            right[x] = i;
            count[x]++;
        }

        int ans = nums.size();
        int degree = 0;
        for (const auto& entry : count) {
            degree = std::max(degree, entry.second);
        }

        for (const auto& entry : count) {
            if (entry.second == degree) {
                ans = std::min(ans, right[entry.first] - left[entry.first] + 1);
            }
        }
        return ans;
    }
};
