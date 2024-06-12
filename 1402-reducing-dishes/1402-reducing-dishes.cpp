class Solution {
public:
    int solve(int i,int j,vector<int>& arr,int time,vector<vector<int>>&dp)
    {
        if(i==j)
        return 0;
        if(dp[i][time]!=-1)
        return dp[i][time];

        return dp[i][time]=max(arr[i]*time+solve(i+1,j,arr,time+1,dp),solve(i+1,j,arr,time,dp));
    }
    int maxSatisfaction(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        sort(arr.begin(),arr.end());
        
        return solve(0,n,arr,1,dp);
    }
};