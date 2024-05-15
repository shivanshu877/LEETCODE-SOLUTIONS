class Solution {
public:
int n;
bool valid(int i,int j){
    return (i>=0 && i<n && j>=0 && j<n);
}
bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

vector<vector<int>> f(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> distanceGrid(n, vector<int>(n, INT_MAX)); // Initialize with maximum value
    queue<pair<int, int>> q;

    // Initialize the queue and distance for '1' cells
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                q.push({i, j});
                distanceGrid[i][j] = 0;
            }
        }
    }

    // Directions: up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // BFS to compute minimum distances
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (isValid(newX, newY, n) && distanceGrid[newX][newY] == INT_MAX) {
                distanceGrid[newX][newY] = distanceGrid[x][y] + 1;
                q.push({newX, newY});
            }
        }
    }
    return distanceGrid;
}
    int maximumSafenessFactor(vector<vector<int>>& grid) {
         n=grid.size();
          if(grid[n-1][n-1]==1 || grid[0][0]==1) return 0;
        vector<vector<int>>dis=f(grid);
        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<int>delr={-1,0,1,0};
        vector<int>delc={0,1,0,-1};
        pq.push({dis[0][0],{0,0}});
        vis[0][0]=1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int ds=it.first;
            int i=it.second.first;
            int j=it.second.second;
            if(i==n-1 && j==n-1) return pq.top().first;
            for(int l=0; l<4; l++){
                int nrow=i+delr[l];
                int ncol=j+delc[l];
                if(valid(nrow,ncol) && grid[nrow][ncol]!=1 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    int ds1=dis[nrow][ncol];
                    pq.push({min(ds,ds1),{nrow,ncol}});
                }
            }

        }
        return 0;

    }
};