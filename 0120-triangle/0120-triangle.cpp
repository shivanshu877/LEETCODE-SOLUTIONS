class Solution {
public:
    int f(int i, int j, vector<vector<int>>& tri, vector<vector<int>>&dp){
        if(i>tri.size() || j>tri[i-1].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=tri[i-1][j-1];
        int bottom=f(i+1, j, tri, dp);
        int bottomNext=f(i+1, j+1, tri, dp);
        return dp[i][j] = res + min(bottom, bottomNext);
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return f(1, 1, tri, dp);
    }
};