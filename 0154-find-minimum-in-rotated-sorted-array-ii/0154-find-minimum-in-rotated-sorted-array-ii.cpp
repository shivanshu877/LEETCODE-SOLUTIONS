class Solution {
public:
    int findMin(vector<int>& vec) {
     set<int> ans (vec.begin() , vec.end());
     int mini  = INT_MAX ;
     for(  auto x : ans )
     {
         if ( x < mini)
         mini = x  ;
     }
    return mini;
    }
};