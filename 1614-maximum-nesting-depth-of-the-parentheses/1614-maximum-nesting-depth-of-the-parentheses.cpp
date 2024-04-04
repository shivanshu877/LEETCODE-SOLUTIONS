class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int a  = 0 ; 
        for(auto it : s ) {
            if(it == '(' ){
                open++;
               if(open  > a ) a = open ;
            }
            else if (it == ')' ) open-- ;
            else {
                
            }
        }
        return a ;
    }
};