class Solution {
public:
    bool canPartition(vector<int>& arr) {
             int n= arr.size();
 int z  = accumulate(arr.begin(), arr.end(),0) ;
        if(z % 2  == 1 ) return false;

        int k =z  / 2 ;
       vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            bool notTaken = dp[ind - 1][target];

            bool taken = false;
            if (arr[ind] <= target) {
                taken = dp[ind - 1][target - arr[ind]];
            }

            dp[ind][target] = notTaken || taken;
        }
    }

    return dp[n - 1][k];

    }
};