#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int> &a) {
        std::vector<int> ans;

        for (int i = 0; i < a.size(); ++i) {
            int asteroid = a[i];
            if (asteroid > 0 || ans.empty() || ans.back() < 0) {
                ans.push_back(asteroid);
            } else {
                while (!ans.empty() && ans.back() > 0 && std::abs(asteroid) > ans.back()) {
                    ans.pop_back(); // Destroy smaller asteroids.
                }
                
                if (ans.empty() || ans.back() < 0) {
                    ans.push_back(asteroid); // Current asteroid survives.
                } else if (ans.back() == std::abs(asteroid)) {
                    ans.pop_back(); // Both asteroids annihilate each other.
                }
            }
        }

        return ans;
    }
};
