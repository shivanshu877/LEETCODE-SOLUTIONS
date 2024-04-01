class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin() , s.end()) ;  
        int n = s.size();
        int ans = 0 ;

        int i = 0 ;
        if( i < n && i == 0 && s[i] == ' ' ){
                while(s[i] == ' ') i++;
        }
        while( i < n  && s[i] != ' ')  {
            ans++;
            i++;
        }
        return ans ;
    }
};