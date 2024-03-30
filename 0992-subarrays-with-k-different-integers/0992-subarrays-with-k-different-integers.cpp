class Solution {
public:
    
    int f (vector<int> & nums , int  k) {
        int n = nums.size() ;
        unordered_map<int, int> store ;
        int ans = 0 ; 
        for(int right = 0 , left = 0  ; right < n ; right++ ){
            store[nums[right]]++ ;
            while(store.size() > k) {
                store[nums[left]]--;
                if(store[nums[left]] == 0) store.erase(nums[left]) ;
                left++;
            }
            ans += right - left + 1  ;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size() ;
        int ans = 0  ;
        ans += f(nums , k ) ;
        ans -= f(nums , k -1) ;
        return ans  ;
    }
};