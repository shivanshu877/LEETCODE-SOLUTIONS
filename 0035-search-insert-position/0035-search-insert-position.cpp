class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       
        int mid = 0;
        int low = 0;
        int found =0;
        int high = nums.size()-1;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(target==nums[mid]){
                found = 1;
                return mid;
            }
            else
                if(nums[mid]>target)
                    high = mid-1;
            else
                low = mid+1;
        }
      
        return high +1;
    }

};