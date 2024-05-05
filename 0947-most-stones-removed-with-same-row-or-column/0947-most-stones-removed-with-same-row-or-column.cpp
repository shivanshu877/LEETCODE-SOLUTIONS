#include <vector>
#include <unordered_map>

class DSU {
    std::unordered_map<int, int> parent;
public:
    int find(int x) {
        if (!parent.count(x)) parent[x] = x;
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    int removeStones(std::vector<std::vector<int>>& stones) {
        DSU dsu;
        for (const auto& stone : stones) {
            dsu.unite(stone[0], ~stone[1]); // Use ~ to differentiate rows and columns
        }
        
        std::unordered_map<int, int> groups;
        for (const auto& stone : stones) {
            groups[dsu.find(stone[0])]++;
        }
        
        int removedStones = 0;
        for (const auto& group : groups) {
            removedStones += group.second - 1; // Leave one stone in each group
        }
        
        return removedStones;
    }
};
