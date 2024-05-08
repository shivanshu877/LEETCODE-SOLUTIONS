class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int , string , greater<int>> a ;
        for(auto it : score) {
            a[it] = " ";
        }
        int n = score.size();
        int i = 1;
        for(auto& it  : a ){
            
           if( i ==  1) it.second = "Gold Medal";
           else if( i == 2) it.second = "Silver Medal";
           else  if( i == 3) it.second = "Bronze Medal";
           else it.second = to_string(i);
            i++;
        }
        vector<string> ans;
        for(int it : score ){
            
            ans.push_back(a[it]);
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<string> findRelativeRanks(vector<int>& score) {
//         map<int, string> a;
//         for(auto it : score) {
//             a[it] = " ";
//         }
//         int n = score.size();
//         int i = n;
//         for(auto it = a.rbegin(); it != a.rend(); ++it) {
//             if(i == n) it->second = "Gold Medal";
//             else if(i == n - 1) it->second = "Silver Medal";
//             else if(i == n - 2) it->second = "Bronze Medal";
//             else it->second = to_string(n - i + 1);
//             i--;
//         }
//         vector<string> ans;
//         for(int it : score) {
//             ans.push_back(a[it]);
//         }
//         return ans;
//     }
// };