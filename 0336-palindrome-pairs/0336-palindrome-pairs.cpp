class Solution {
public:
    bool isPalindrome(const string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> reversedIndexMap;
        vector<vector<int>> result;

        // Store the reversed words in a map with their indices
        for (int i = 0; i < words.size(); i++) {
            string reversedWord = words[i];
            reverse(reversedWord.begin(), reversedWord.end());
            reversedIndexMap[reversedWord] = i;
        }

        // Find all pairs
        for (int i = 0; i < words.size(); i++) {
            string currentWord = words[i];
            for (int j = 0; j <= currentWord.size(); j++) {
                // Split the word into two parts: prefix and suffix
                string prefix = currentWord.substr(0, j);
                string suffix = currentWord.substr(j);

                if (isPalindrome(prefix)) {
                    auto it = reversedIndexMap.find(suffix);
                    if (it != reversedIndexMap.end() && it->second != i) {
                        result.push_back({it->second, i});
                    }
                }
                if (j < currentWord.size() && isPalindrome(suffix)) {
                    auto it = reversedIndexMap.find(prefix);
                    if (it != reversedIndexMap.end() && it->second != i) {
                        result.push_back({i, it->second});
                    }
                }
            }
        }

        return result;
    }
};
