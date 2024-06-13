#include <string>
#include <cmath> // for pow
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();
        
        int i = 0, j = 0;
        
        while (i < n1 || j < n2) {
          
            int num1 = 0, num2 = 0;
            
            while (i < n1 && version1[i] != '.') {
                cout << num1 << "num1 "  << endl;
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            
            while (j < n2 && version2[j] != '.') {
                  cout << num2 << "num2 "  << endl;
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            
            if (num1 < num2) return -1;
            else if (num1 > num2) return 1;
            
            i++;
            j++;
        }

        return 0;
    }
};
