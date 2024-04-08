#include <vector>
#include <deque>
#include <climits>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        if (k == 1) return nums;
        
        std::deque<int> window;
        std::vector<int> result;
        
        // Initialize the deque for the first window
        for (int i = 0; i < k; ++i) {
            while (!window.empty() && nums[i] >= nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
        }
        result.push_back(nums[window.front()]);
        
        // Process the rest of the elements
        for (int i = k; i < nums.size(); ++i) {
            // Remove elements outside the window
            if (!window.empty() && window.front() <= i - k) {
                window.pop_front();
            }
            
            // Remove smaller elements from the end
            while (!window.empty() && nums[i] >= nums[window.back()]) {
                window.pop_back();
            }
            
            window.push_back(i);
            result.push_back(nums[window.front()]);
        }
        
        return result;
    }
};
