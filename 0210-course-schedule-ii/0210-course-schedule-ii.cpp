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

    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> vis(n, 0);
        vector<int> path(n, 0);
        vector<int> answer ;
        vector<vector<int>> adj(n);
        for (int i = 0; i < p.size(); i++) {
            adj[p[i][0]].push_back(p[i][1]);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (!dfs(i, adj, vis, path , answer)) {
                    return {};
                }
            }
        }

        return answer;
    }
};