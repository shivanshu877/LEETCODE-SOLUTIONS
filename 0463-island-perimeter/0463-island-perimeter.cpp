class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans  = 0 ;
        int m = grid.size() ;
        int n =  grid[0].size() ;
        for(int i = 0  ; i< m ; i++){
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == 1  ){
                    int temp = 0 ;
                    //left
                    if(j-1 >= 0 ){ if(grid[i][j-1] == 1) temp++ ; } 
                    //right
                    if(j+1 <= n-1 ){ if(grid[i][j+1] == 1) temp++ ; }
                    //up
                    if(i-1 >= 0 ){ if(grid[i-1][j] == 1)  temp++ ; }
                    //down 
                    if(i+1 <= m-1 ){ if(grid[i+1][j] == 1)  temp++ ; }
                    ans += 4 - temp ;
                }
            }
        }
        return ans;
    }
};