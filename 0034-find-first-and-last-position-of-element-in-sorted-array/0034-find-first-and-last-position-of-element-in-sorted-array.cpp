class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        vector<int> temp;
        for( int i = 0 ; i< nums.size() ; i++) {
              if(nums[i] ==  target)
              temp.push_back(i);
        }
        if(temp.size() == 0) {
            ans.push_back(-1);
            ans.push_back(-1);
        }
           else if(temp.size() == 1) {
            ans.push_back(temp[0]);
            ans.push_back(temp[0]);
        }
        else {
        ans.push_back(temp[0]);
        ans.push_back(temp[(temp.size() -1)]);
        }

        return ans;
    }
};