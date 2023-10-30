class Solution {
public:
unsigned int countBits( unsigned int num) 
{     
    
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count ;
} 
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> ans (16);
        vector<int> a;
        for(auto x : arr){
            int  temp = countBits((unsigned int)x);
              ans[temp].push_back(x);
        }
        for(auto x :ans){
            sort(x.begin() , x.end()) ;
            for(auto y: x){
            a.push_back(y);
            }
        }
    return a ;
    }

};