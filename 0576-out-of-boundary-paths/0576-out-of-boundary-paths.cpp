class Solution {
public:
    int MOD = 1e9 + 7;
    
    int f(int m, int n, int maxMove, int sR, int sC, int move, vector<vector<vector<int>>>& dp) {
        if (sR < 0 || sC < 0 || sR >= m || sC >= n) {
            return 1;
        }
        if (move == maxMove) {
            return 0;
        }
        if (dp[sR][sC][move] != -1) {
            return dp[sR][sC][move];
        }
        
        vector<pair<int, int>> dir {{0,1}, {1,0}, {-1,0}, {0,-1}};
        int ans = 0;
        for (auto it : dir) {
            int x = it.first + sR;
            int y = it.second + sC;
            ans = (ans + f(m, n, maxMove, x, y, move + 1, dp)) % MOD;
        }
        
        dp[sR][sC][move] = ans;
        return ans;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove, -1)));
        return f(m, n, maxMove, startRow, startColumn, 0, dp);
    }
};
