class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> ans;
    int maxLength = INT_MIN;
    int left = 0;
    int n = s.size();
    int right = 0;

    while (right < n) {
      while (left < right && (ans.find(s[right]) != ans.end() && ans[s[right]] == 1)) {
        ans[s[left]]--;
        if (ans[s[left]] == 0) {
          ans.erase(s[left]);
        }
        left++;
      }

      ans[s[right]]++;
      maxLength = max(maxLength, right - left + 1);
      right++;
    }

    return maxLength  ==  INT_MIN ?  0 : maxLength ;
  }
};
