class Solution {
public:
    int f(vector<int> & nums , int goal){
        if(goal < 0) return 0 ;
        int left =0 ; 
        int right = 0 ;
        int sum =0 ;
        int count =0 ;
        while( right < nums.size()) {
            sum += nums[right] ;
            while(sum > goal ){
                sum -= nums[left];
                left++;
            }
            count +=  right - left +1  ;
            right++;
            
        }
        return count ;
    }
     int numSubarraysWithSum(vector<int>& nums, int goal) {
       return f(nums , goal) - f(nums ,goal -1) ;
    }
};