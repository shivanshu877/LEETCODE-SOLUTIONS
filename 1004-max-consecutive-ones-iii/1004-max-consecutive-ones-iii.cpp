class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroes  =0;
        int ones = 0 ;
        int left =0 ;
        int right = 0;
        int n = nums.size() ;
        int rv = 0;
        for(right =0 ; right < n ;right++) {
           if(nums[right] == 0 )
            zeroes++ ;
            while(  zeroes > k ){
            if(nums[left] == 0 )
            zeroes-- ;
            left++;
           }
            rv = max( rv , right - left +1) ;
        }
        return rv;
    }
};