class Solution {
public:  
        
        long f(int idx , int n , vector<int> ans , int state , vector<vector<vector<int>>> dp  , int k) {
        if( idx  == n  || k  ==   0 ) return 0 ;
        long profit   = 0 ;
        if ( dp[idx][state][k] != -1 ) return dp[idx][state][k] ;
        if(state){
            profit = max(( -ans[idx] + f(idx  +1 , n,  ans , 0, dp , k))  , (0 + f(idx  + 1,n ,   ans , 1, dp , k))) ;
        }
        else{
            profit = max((  ans[idx] + f(idx +1 ,n , ans , 1, dp , k-1))   , (0 + f(idx +  1  ,  n , ans , 0, dp , k))) ;
            
        }
        return dp[idx][state][k] = profit;
    } 
    int maxProfit(vector<int>& Arr) {
        int n = Arr.size() ;
       vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));


    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy == 0) {
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
                                           -Arr[ind] + dp[ind + 1][1][cap]);
                }

                if (buy == 1) {
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
                                           Arr[ind] + dp[ind + 1][0][cap - 1]);
                }
            }
        }
    }

    return dp[0][0][2];
    }
};