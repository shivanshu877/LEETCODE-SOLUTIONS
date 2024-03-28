class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int , int> ans ;
        int returnvalue = INT_MIN;
        int left =0 ;
        for( int right = 0 ;  right < nums.size() ; right++) {
            ans[nums[right]]++;
                if(ans[nums[right]] > k) {
                    while(nums[left]!= nums[right] && left < right){ 
                    ans[nums[left]]--;
                    if(ans[nums[left]] <= 0)ans.erase(nums[left]);
                    left++ ;
                    }
                    ans[nums[left]]--;
                    if(ans[nums[left]] <= 0)ans.erase(nums[left]);
                    left++;                    
                }
             returnvalue = max( (right -left +1) , returnvalue) ;
            }
        
        return returnvalue;
    }
};