#include <stack>
#include <string>

class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        int i = 0;
        stack<char> st;
        
        while (i < n) {
            if (!st.empty() && ((st.top() >= 'a' && st.top() <= 'z' && s[i] >= 'A' && s[i] <= 'Z' && st.top() == tolower(s[i]))
                         || (st.top() >= 'A' && st.top() <= 'Z' && s[i] >= 'a' && s[i] <= 'z' && st.top() == toupper(s[i])))) {
                st.pop();
            } else {
                st.push(s[i]);
            }
            i++;
        }
        
        string z = "";
        while (!st.empty()) {
            z = st.top() + z;
            st.pop();
        }
        
        return z;
    }
};
