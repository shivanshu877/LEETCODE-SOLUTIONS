class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i=0,j=0;
        int sum=0,ans = INT_MAX;
        vector<int>bits(32,0);
        while(j<nums.size()){
            sum|=nums[j];
            for(int z = 0;z<32;z++){
                 if((1<<z) & nums[j])
                    bits[z]++;
            }
            j++;
            while(i<j && sum>=k){
                ans = min(ans,j-i);
                for(int z = 0;z<32;z++){
                    if((1<<z) & nums[i])
                    {
                        bits[z]--;
                        if(bits[z]==0)
                            sum^=(1<<z);
                    }
                }
                i++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};