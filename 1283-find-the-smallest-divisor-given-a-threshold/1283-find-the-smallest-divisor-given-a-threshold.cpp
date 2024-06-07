class Solution {
public:
     int sum(vector<int > ans , int div ) {
         int s = 0 ;
         int n  = ans.size() ;
         for( int i =0 ; i < n;i++) {
             s += ceil ( (double)(ans[i])   / (double)(div) );
         }
         return s ;
     }
    
    
    int smallestDivisor(vector<int>& nums, int limit) {
        
        int low  =1 ;
        int high  = *max_element(nums.begin() , nums.end()) ;
        while(low <= high) {
            int mid = (low + high ) /2 ;
            if(sum(nums , mid) <= limit ) {
                high = mid -1 ;
            }
            else {
                low = mid+1 ;
            }
        }
        return low ;
    }
};