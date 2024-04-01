class Solution {
public:
            string ans = "";

    int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // Create a 2D DP array to store the length of the LCS
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Initialize the first row and first column to 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    // Fill in the DP array
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }
    
            int i = s1.size() ;
            int j = s2.size() ;
             while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
        ans  = s1[i-1] + ans;
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
     ans  = s1[i-1] + ans;        i--;
    } else {
      ans  =  s2[j-1] + ans ; 
        j--;
    }
  }  
  while(i>0){
      ans  = s1[i-1] + ans;
      i--;
  }
  while(j>0){
      ans  =  s2[j-1] + ans ; 
      j--;
  }

     
        
    
    return dp[n][m];
}
    string shortestCommonSupersequence(string str1, string str2) {
        lcs(str1  , str2 );
        return ans;
    }
};