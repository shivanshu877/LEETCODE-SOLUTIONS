class Solution {
public:
    int maxDepth(string s) {
        stack<char> ans ;
        int a  = 0 ; 
        for(auto it : s ) {
            if(it == '(' ){
                ans.push(it);
               if(ans.size() > a ) a =ans.size() ;
            }
            else if (it == ')' ) ans.pop() ;
            else {
                
            }
        }
        return a ;
    }
};