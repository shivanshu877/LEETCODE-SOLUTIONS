class Solution {
public:
    void dfs(int node, const vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (int x : adj[node]) {
            if (!vis[x]) {
                dfs(x, adj, vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        
        // Build adjacency list
        for (const auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                count++;
            }
        }
        
       
        return count -1;
    }
};
