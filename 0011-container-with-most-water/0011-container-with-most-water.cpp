class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0 ; 
        int high = height.size() -1 ; 
        int ans = INT_MIN ;
        while(low < high){
            if(height[low] <= height[high]) {
            ans = max(    ans     , min(height[low]   , height[high] ) * (high - low ) );
                low++;
            }
            else {
            ans = max(    ans     , min(height[low]   , height[high] ) * (high - low ) );
               high--;
            }
        }
        return ans;
    }
};