class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int ans = INT_MIN ;
        int rsum =  0 ;
        for(int i = 0 ; i< nums.size() ;i++) {
             rsum = max(nums[i] , nums[i] + rsum) ;
             ans = max(ans , rsum);
        }
        return ans;
        
        //  int curMax = 0, maxTillNow = INT_MIN;
        // for(auto c : nums)
        //     curMax = max(c, curMax + c),
        //     maxTillNow = max(maxTillNow, curMax);
        // return maxTillNow;
    }
};