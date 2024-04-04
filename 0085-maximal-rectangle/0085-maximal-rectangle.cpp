class Solution {
public:
    int f(vector<int> nums , int n){
        vector<int>left (n , -1);
        vector<int> right(n , -1);
        stack<int> st ; 
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i] )
               st.pop();
             if(st.empty())left[i] = 0;
            else left[i] = st.top() +1 ;
            st.push(i);
        }
        while(!st.empty())st.pop();
         for(int i = n-1 ; i >=0  ; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i] )
               st.pop();
             if(st.empty())right[i] = n-1;
            else right[i] = st.top()  - 1 ;
            st.push(i);
        }
        for( int i = 0 ; i < n ; i++){
            ans = max( ans , (nums[i] * (right[i] -left[i] +1)));
        }
        return ans ;   
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
                int m = matrix.size() ;
        int n = matrix[0].size();
       
 
        vector<vector<int>> ans( m , vector<int>(n ,  0)) ;
         for( int i = 0 ; i < m ; i++) {
        for(int  j =  0 ; j < n ; j++) {
                ans[i][j] =  matrix[i][j] -'0' ;                  
       }
        }
         for( int i = 1 ; i < m ; i++) {
        for(int  j =  0 ; j < n ; j++) {
              if(ans[i-1][j] > 0 && ans[i][j]  > 0 )ans[i][j] = 1 + ans[i-1][j]  ;
         cout << ans[i][j] <<" " ;  
        }
            cout<< endl;
        }
        int a  = 0 ;
        for(auto it : ans) {
        a= max(a , f(it , n));
        }
        return a;
    }
};