class Solution {
public:
    int f(vector<int> nums , int  k ) {
        unordered_map<int , int>  m;
        int left  =0 ;
        int ans = 0 ;
        int n = nums.size() ;
        for(int right = 0 ; right < n ;right++){
            m[nums[right]]++;
            while( m.size() > k){
                m[nums[left]]--;
                if(m[nums[left]] == 0)m.erase(nums[left]) ;
                left++;
            }
            ans += right -left+1 ;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums , k) - f(nums, k-1) ;
    }
};