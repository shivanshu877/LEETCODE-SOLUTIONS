class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long x = 1;
        int ans = 0;
        for (int i = 0; x <= n;) {
            if (i < nums.size() && nums[i] <= x) {
                cout << nums[i] << " " <<  x <<" " << endl ;
                x += nums[i++];
                
            } else {

                ++ans;
                cout<< ans <<"  " ;
                x <<= 1;
                cout<< x << " "<< endl;
            }
        }
        return ans;
    }
};