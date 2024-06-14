class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int max_ele = 1000001;
        
        vector<int> ans( max_ele + 1 , 0) ;
        for(auto it : nums){
        ans[it]++;
        }
        int right = 0 ;
        int a = 0 ;
    
        cout << endl;
        for(right = 0 ; right <= max_ele; right++) {
            if(ans[right] > 1 ){
                 int temp = right + 1;
                  int left = ans[right] - 1 ;
                while(left && temp <= max_ele ){
                     if(ans[temp] == 0 ){
                      left--;
                      ans[temp] = -1 ;
                      a += (temp - right) ;
                     }
                         
                temp++;
                }
            }
        }
        return a ;
    }
};