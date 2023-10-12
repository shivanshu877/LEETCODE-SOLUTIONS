class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> ans(n) ;
        iota (begin(ans), end(ans), 1); 
        do {
            k--;
        }
        while(  (k != 0 )  && (next_permutation(ans.begin() , ans.end())));
       string s ;
       for(auto x : ans) {
           s += to_string(x);
       }
    return s;
        }
};