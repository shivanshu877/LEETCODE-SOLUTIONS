class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(edges.size() == 0 ) return true ;
        vector<vector<int>> adj(n) ;
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
        }
    
        vector<int> vis(n ,  0) ;
        queue<int> q; 
        q.push(source) ;
        while(!q.empty()) {
            auto x = q.front() ;
            q.pop() ;
      
            for( auto it : adj[x]) {
                if (it == destination) return true;
                else{
                    if(!vis[it]){
                        vis[it] = 1 ;
                        q.push(it);
                    }
                }
            }
        }
        return false;
    }
};