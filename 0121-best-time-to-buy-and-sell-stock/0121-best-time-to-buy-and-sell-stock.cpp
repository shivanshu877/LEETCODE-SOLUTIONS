class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int mini = nums[0];
        int profit = 0 ;
        for(int i = 1 ; i  < nums.size(); i++){
            int temp = nums[i] - mini ;
            profit = max(profit , temp );
            mini  = min(mini , nums[i]) ;
        }
        return profit  ;
    }
};