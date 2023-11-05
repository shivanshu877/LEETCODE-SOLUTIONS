class Solution {
public: 

    void comb(vector<int> & input ,  vector<int>& output  ,  vector<vector<int>> & ans ,  int target , int n)  {
              if( target == 0 )  {
              ans.push_back(output);
              return ;
              }
            for( int i =  n ;  i<input.size() ; i++) {
            if ( i > n  && (input[i] ==  input[i-1])) continue ; 
            if(input[i] > target ) break;

          output.push_back(input[i]);
          comb(input , output , ans    , target  - input[i] ,i+1 ) ;
          output.pop_back();


            }

      
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin() , candidates.end()) ; 
          vector<int>output ;
          vector<vector<int>>  ans ; 
          comb(candidates, output , ans , target , 0 );
  return ans ;

    }
};