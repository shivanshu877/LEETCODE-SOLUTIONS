class Solution {
public:
     int f ( vector<int> nums  ){
        int n = nums.size() ;
        vector<int> left (n) ;
        vector<int> right(n) ;
        stack<int>  st ;
        for( int i=0 ; i < n ;i++) {
            while(!st.empty() && nums[st.top()] >= nums[i] )st.pop() ;
            if(st.empty()) left[i] =  0;
           else left[i]  = st.top()+1 ;
            st.push(i);
        }
        stack<int>  st1 ;
        for( int i = n-1 ; i >=  0 ;i--) {
            while(!st1.empty() && nums[st1.top()] >= nums[i] )st1.pop() ;
            if(st1.empty()) right[i] = n -1;
           else  right[i]  = st1.top() -1  ;
            st1.push(i);
        }
        int ans = 0;
      
        for( int i = 0 ; i< n ; i++) {
            ans = max( ans , nums[i] * (right[i] - left[i]   +   1 ));    
        }
        return ans ;     
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
       int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        
        // Create and initialize the ma vector
        vector<vector<int>> ma(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (i == 0)
                    ma[i][j] = matrix[i][j] - '0';
                else if (ma[i - 1][j] > 0 && matrix[i][j] > '0')
                    ma[i][j] = ma[i - 1][j]  + matrix[i][j] - '0';
                else
                    ma[i][j] = matrix[i][j] - '0';
            }
        }
        
    
        int ans = 0 ;
        for(auto it: ma) {
          int temp =  f(it) ;
           ans = max(ans , temp) ;
        }
        return ans; // Placeholder return value
    }
};