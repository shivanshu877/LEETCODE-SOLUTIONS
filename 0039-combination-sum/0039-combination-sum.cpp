class Solution {
public:
   
    void solver(  vector<vector<int>>& ans  , vector<int>&  can ,vector<int>&  ccom  ,int target , int currindex , int total) {

       if(total > target) return ;
       if(total ==  target ){
           ans.push_back(ccom);
           return  ;
       } 
       

        
        for( int i = currindex  ; i <can.size() ; i++){
            ccom.push_back(can[i]);
            total = total + can[i] ;
            solver(ans , can , ccom , target , i , total) ;
            ccom.pop_back() ;
            total =  total-can[i] ;
        }


        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int> ccom ;
        vector<vector<int>> ans;
       solver( ans ,  candidates ,ccom ,  target  , 0 , 0) ;
       return ans ;
    }
};
