class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int , int> ans ;
        int returnvalue = INT_MIN;
        int left = -1 ;
        for( int right = 0 ;  right < nums.size() ; right++) {
            ans[nums[right]]++;
                while(ans[nums[right]] > k) {
                   left++;
                   ans[nums[left]]--;
                }
             returnvalue = max( (right -left ) , returnvalue) ;
            }
        
        return returnvalue;
    }
};