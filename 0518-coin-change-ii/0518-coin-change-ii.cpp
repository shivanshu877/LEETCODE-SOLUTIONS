#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<string, int> a;

    int f(int k, int s, vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            if (s == 0) return 1;
            return 0;
        }
        if (a.find(to_string(idx) + " " + to_string(s)) != a.end()) {
            return a[to_string(idx) + " " + to_string(s)];
        }
        int take = 0;
        if (nums[idx] <= s)
            take = f(k, s - nums[idx], nums, idx);
        int nottake = f(k, s, nums, idx + 1);
        a[to_string(idx) + " " + to_string(s)] = take + nottake;
        return a[to_string(idx) + " " + to_string(s)];
    }

    int change(int amount, vector<int>& coins) {
        int ans = 0;
        ans = f(amount, amount, coins, 0);
        return ans;
    }
};
