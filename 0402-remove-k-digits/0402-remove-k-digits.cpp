#include <string>
#include <stack>

class Solution {
public:
    string removeKdigits(string num, int k) {
        std::stack<char> st;
        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }
        
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        std::string result = "";
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin() , result.end());
        int leading_zeros = 0;
        for (char digit : result) {
            if (digit == '0') {
                leading_zeros++;
            } else {
                break;
            }
        }
        result = result.substr(leading_zeros);
        
        return result.empty() ? "0" : result;
    }
};
