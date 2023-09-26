class Solution {
public:
    unordered_map<Node* , Node*> mp;
    
    Node* cloneGraph(Node* node) {
        if(node == NULL)
        {
            return NULL;
        }
        
        Node* first = new Node(node -> val, {});
        mp[node] = first;
        
        queue<Node*> q; 
        q.push(node);
    
        while(q.empty() == false) 
        {
            Node* curr = q.front(); 
            q.pop();
            
            for(auto adj: curr -> neighbors) // now travel in adjcant
            {
                if(mp.find(adj) == mp.end()) // if not present in map
                {
                    mp[adj] = new Node(adj -> val, {}); // then create copy
                    q.push(adj); // push nto the queue
                    
                }
                
                mp[curr] -> neighbors.push_back(mp[adj]); // in current node push adjcant node
            }
        }
        
        return mp[node];
    }
};