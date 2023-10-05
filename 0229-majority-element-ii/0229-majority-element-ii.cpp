class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         int  times =  nums.size() /  3  ;
          map < int , int > total_count  ;
          for( int i = 0 ; i < nums.size() ; i++) {
            total_count[nums[i]]++ ; 
          }
          vector< int > ans ;
          for(auto x  : total_count ){
              if(x.second > times) 
              ans.push_back(x.first) ;
          }

     return ans ;
    }
};