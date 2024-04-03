class Solution {
public:
    
    int lengthOfLIS(vector<int>& arr) {
        int n  = arr.size() ;
        int maxi  = 1 ;
        vector<int> dp ( n  , 1);
        for(int i = 0  ; i< n ; i++) {
        for( int prev = 0 ; prev < i ; prev++)
                if(arr[prev] < arr[i]){
                    dp[i]  = max(dp[i] ,1 +  dp[prev]);
                }
            maxi = max(maxi , dp[i]); 
            }
        return maxi;
       
    }
};