class Solution {
public:
//     long f(int idx , int n , vector<int> ans , int state , vector<vector<int>> dp) {
//         if( idx  == n ) return 0 ;
//         long profit   = 0 ;
//         if ( dp[idx][state] != -1 ) return dp[idx][state] ;
//         if(state){
//             profit = max(( -ans[idx] + f(idx  +1 , n,  ans , 0, dp))  , (0 + f(idx  + 1,n ,   ans , 1, dp))) ;
//         }
//         else{
//             profit = max((  ans[idx] + f(idx +1 ,n , ans , 1, dp))   , (0 + f(idx +  1  ,  n , ans , 0, dp))) ;
            
//         }
//         return dp[idx][state] = profit;
//     } 
    
    int maxProfit(vector<int>& ans) {
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
            profit = max( (ans[idx] + dp[idx+1][1] ) , dp[idx  + 1][0]) ;            
        }
                dp[idx][state] = profit;
                
            }
        }
       return  dp[0][1] ;
    }
};
