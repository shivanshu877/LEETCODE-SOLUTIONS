class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int K) {
        vector<pair<int, int>> adj[n];
        for (auto x : flights) {
            adj[x[0]].push_back({x[2], x[1]});
        
        }
        vector<pair<int , int >> dstw;
        vector<pair<int, int>> dis(n, {INT_MAX, 0});
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            bfs;
        bfs.push({0, src, 0});
        dis[src].first = 0;
        int i =1;
        while (!bfs.empty()) {
            auto x = bfs.top();
            int weight = get<2>(x);
            int node = get<1>(x);
            int k =get<0>(x);
            bfs.pop();
            if(k > K) continue;
            for (auto adjNode : adj[node]) {
                int adjw = adjNode.first;
                int adjn = adjNode.second;
                if ( weight + adjw < dis[adjn].first){
                        dis[adjn].first =  weight + adjw  ;                      
                        bfs.push({k+1, adjn   , weight + adjw });
                }
            }
        
        }
        return  dis[dst].first==INT_MAX?-1:dis[dst].first;
    }
};