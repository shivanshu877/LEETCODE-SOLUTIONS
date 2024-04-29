class Solution {
public:
     bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& path , vector<int>& result  ) {
        vis[node] = 1;
        path[node] = 1;
        for (auto x : adj[node]) {
            if (!vis[x]) {
                if (dfs(x, adj, vis, path , result) == false)
                    return false;
            } else if (path[x]) {
                return false;
            }
        }
        path[node] = 0;
        result.push_back(node) ;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n  = adj.size();
        vector<int> vis(n, 0);
        vector<int> path(n, 0);
        vector<int> temp ;
        for (int i = 0; i < n; i++) {
            
                vector<int> answer ;
                if (!dfs(i, adj, vis, path , answer)) {
                    
                }
                else {
                  temp.push_back(i);        
                }
            
        }
        return temp;
    }
};