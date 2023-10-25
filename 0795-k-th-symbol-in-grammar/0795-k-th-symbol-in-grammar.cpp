class Solution {
public:
    int kthGrammar(int n, int k) {
         string binaryK = bitset<32>(k - 1).to_string();
        
        int countOnes = 0;
        for (char c : binaryK) {
            if (c == '1') {
                countOnes++;
            }
        }
        return countOnes % 2;
    }
};