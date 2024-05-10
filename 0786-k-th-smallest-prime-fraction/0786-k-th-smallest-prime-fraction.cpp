class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int> ans;
        int n =  arr.size();
priority_queue<pair<double, pair<int, int>>> pq;
        for( int i = 0 ; i< n ; i++) {
            for(  int j = 0 ; j < n ; j++) {
                if(i != j ){
                    pq.push({ double( double(arr[i])/ double(arr[j]) )  , {i , j}});
                    if(pq.size() > k ){
                        pq.pop();
                    }
                }
            }
        }
      
            // cout<< pq.top().first << " " << pq.top().second.first << " "<<pq.top().second.second << endl;
       ans.push_back(arr[pq.top().second.first]);
       ans.push_back(arr[pq.top().second.second]);
        
        return ans;
    }
};