class Solution {
public:
    int maxProfit(vector<int>& ans, int fee) {
          int n = ans.size() ;
        vector<vector<int>> dp ( n + 1 ,vector(2 , 0));
        dp[n][0] = dp[n][1] =  0 ;
        for( int  idx = n -1 ; idx >= 0 ;idx-- ){
            for(int  state = 0 ; state < 2 ; state++) {
                long profit = 0 ;
        if(state){
            profit = max( (-ans[idx] + dp[idx+1][0] ) , dp[idx  + 1][1]) ;
        }
        else{
            profit = max( (ans[idx] + dp[idx+1][1]  - fee ) , dp[idx  + 1][0]) ;            
        }
                dp[idx][state] = profit;
                
            }
        }
       return  dp[0][1] ;
    }
};