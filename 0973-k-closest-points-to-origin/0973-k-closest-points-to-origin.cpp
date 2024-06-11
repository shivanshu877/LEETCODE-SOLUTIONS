#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Min-heap to store the distances and corresponding points
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pq;

        // Calculate distances and store them in the heap
        for (int i = 0; i < points.size(); ++i) {
            double dist = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            pq.push({dist, points[i]});
        }

        // Extract the k closest points
        vector<vector<int>> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
