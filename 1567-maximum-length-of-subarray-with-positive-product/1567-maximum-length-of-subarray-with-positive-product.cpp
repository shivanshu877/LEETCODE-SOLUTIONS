class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int maxLen = 0;
        int firstNegative = -1; 
        int lastNegative = -1; 
        int zeroPosition = -1; 
        int countNegatives = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                firstNegative = -1;
                lastNegative = -1;
                zeroPosition = i;
                countNegatives = 0;
            } else {
                if (nums[i] < 0) {
                    countNegatives++;
                    if (firstNegative == -1) {
                        firstNegative = i; 
                    }
                    lastNegative = i; 
                }
                
               
                if (countNegatives % 2 == 0) {
                    maxLen = max(maxLen, i - zeroPosition);
                } else {
                   
                    maxLen = max(maxLen, i - firstNegative);
                }
            }
        }
        
        return maxLen;
    }
};
