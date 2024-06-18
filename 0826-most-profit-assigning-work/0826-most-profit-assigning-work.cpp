class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        reverse(worker.begin() , worker.end());
                reverse(difficulty.begin() , difficulty.end());
                reverse(profit.begin() , profit.end());
            int ans = 0 ;
          int n = worker.size() ;
        for(int i =0  ; i< n ; i++ ) {
            int temp = worker[i];
          int maxi = 0 ;
            for(int j =0 ; j < difficulty.size() ; j++){
                 int diff = difficulty[j] ;
                if(temp >= diff){
                   maxi = max(maxi , profit[j]);
                }
            }
            if(maxi) ans +=maxi;
        }
        return ans;
    }
};