class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         int   l =  nums.size();
         for( int num : nums){
             int index  =  abs(num);
             if(nums[index] < 0)
             return index;
             nums[index] = -nums[index];
         }
      return 0 ;         
    }
};