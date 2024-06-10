class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int anss  = 0 ;
        vector<int> ans = heights;
        sort(heights.begin() , heights.end());
        for(int i =0 ; i < heights.size() ;i++) {
    if (ans[i] != heights[i])anss++;    
        }
        return anss;
    }
};