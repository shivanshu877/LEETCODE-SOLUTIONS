class Solution {
public:
    string removeDuplicates(string s, int k) {
        // Stack to store pairs of characters and their counts
        stack<pair<char, int>> charStack;
        
        for (char c : s) {
           
            if (!charStack.empty() && charStack.top().first == c) {
                // Increment the count of the top element
                charStack.top().second++;
                // If the count reaches k, pop the element from the stack
                if (charStack.top().second == k) {
                    charStack.pop();
                }
            } else {
                // If the character is different, push it to the stack with count 1
                charStack.push({c, 1});
            }
        }
        
        // Build the resultant string from the stack
        string result = "";
        while (!charStack.empty()) {
            result.append(charStack.top().second, charStack.top().first);
            charStack.pop();
        }
        
        // Since we are using a stack, the order of characters is reversed, so reverse the result
        reverse(result.begin(), result.end());
        return result;
    }
};
