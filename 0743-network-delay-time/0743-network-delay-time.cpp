class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      unordered_map <int  , vector<pair<int , int >>> adj ;
      for(auto it : times ){
          adj[it[0]].push_back({it[1] , it[2] }) ;
      }
      vector<int> dist( n + 1, 1e9) ;
      priority_queue<pair<int , int>  , vector<pair <int , int>> ,  greater<pair <int , int>>> bfs; 
      bfs.push({0 , k});
      dist[k] = 0 ;
        while(!bfs.empty()) {
            auto [weight , node ] = bfs.top() ;
            bfs.pop() ;
            for( auto it : adj[node]) {
                auto adjnode =  it.first ;
                auto adjnodeweight = it.second ;
                if( adjnodeweight + weight < dist[adjnode]) {
                    dist[adjnode] = adjnodeweight + weight ;
                    bfs.push({ adjnodeweight + weight , adjnode  }) ; 
                }
            }
        
        }
        int maxi = 0;
        int count = 0;
        for( auto it : dist){
            if(it != 1e9) maxi =  max(maxi , it);
            else{
                count++ ;
            }
        }
         return count > 1 ? -1  : maxi ;
    }
};