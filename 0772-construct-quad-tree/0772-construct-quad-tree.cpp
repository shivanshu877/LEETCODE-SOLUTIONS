//Brute Force
class Solution {
public:
    bool isRoot(int row,int col,int n,vector<vector<int>>& grid){
        int sum=0;
        for(int i=row;i<row+n;i++){
            for(int j=col;j<col+n;j++){
                sum+=grid[i][j];
            }
        }
        return sum==0 or sum==n*n;
    }
    Node* solve(Node* root,int row,int col,int n,vector<vector<int>>& grid){
        if(isRoot(row,col,n,grid)){
            return new Node(grid[row][col]==1,1,NULL,NULL,NULL,NULL);
        }
        root=new Node(grid[row][col],0,NULL,NULL,NULL,NULL);
        root->topLeft=solve(root->topLeft,row,col,n/2,grid);
        root->topRight=solve(root->topRight,row,col+n/2,n/2,grid);
        root->bottomLeft=solve(root->bottomLeft,row+n/2,col,n/2,grid);
        root->bottomRight=solve(root->bottomRight,row+n/2,col+n/2,n/2,grid);
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        return solve(NULL,0,0,grid.size(),grid);
    }
};