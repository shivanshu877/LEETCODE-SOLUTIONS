class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> ans  (text1.size() +1 , vector<int> (text2.size() + 1 ) );
        for( int i = 0 ; i < ans.size() ; i++) ans[i][0] = 0; 
        for( int i = 0 ; i < ans[0].size() ; i++) ans[0][i] = 0; 
        for( int i = 0 ; i < text1.size() ; i++) {
            for( int j = 0 ; j < text2.size() ; j++) {
                int x = i+1;
                int y = j+ 1;
                 if(text1[i] == text2[j]) ans[x][y] =  ans[x-1][y-1]  + 1 ;  
                 else ans[x][y] =max(ans[x-1][y] , max(ans[x-1][y-1] , ans[x][y-1]));       
            }
        }

        return ans[ans.size() - 1][ans[0].size() - 1 ] ; 
    }
};