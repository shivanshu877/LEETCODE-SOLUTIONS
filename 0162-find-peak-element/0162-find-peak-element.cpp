class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int maxx = INT_MIN ;
        int index = 0; 
        for( int i = 0 ; i < nums.size() ; i++){
               if(nums[i] > maxx){
               maxx = nums[i];
                index = i ;
               }
        }
        return index;
    }
};