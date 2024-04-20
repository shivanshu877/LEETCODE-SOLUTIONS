class Solution {
public:
    void dfs(vector<vector<int>>& land , int i , int j , int m , int n , vector<int>& ans){
         if( i <= -1  || j  <= -1 || i >= m || j >= n ) return ;
        land[i][j] = -1 ;
        ans[0] = min(ans[0] , i);
        ans[1] = min(ans[1] , j);
        ans[2] = max(ans[2] , i);
        ans[3] = max(ans[3] , j);
            
        vector<pair<int , int>> dir { {0 , 1} , {1 , 0} ,{0 , -1} , {-1 , 0}} ;
        for( auto it : dir) {
            int x = it.first ;
            int y = it.second ;
            if( i+x >= 0 && j+y >= 0 && i+x < m && j+y < n )
            if(land[i+x][y+j] ==  1 )dfs(land , i+x , j+y , m , n , ans) ;
        }
    } 
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans ;
        int m = land.size() ;
        int n = land[0].size() ;
        for(int i= 0 ; i < m ; i++)
         for(int j =  0 ; j < n ; j++ )
            if (land[i][j] == 1 ){
        vector<int> temp {  INT_MAX , INT_MAX, INT_MIN , INT_MIN } ;
           dfs(land , i , j ,  m  , n , temp ) ;
           ans.push_back(temp) ;
            }
            return ans;
    }
};