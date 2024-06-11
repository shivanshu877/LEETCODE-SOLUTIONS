class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<double , vector<int> > ans;
        vector<vector<int>> anss;
        for( int i  = 0 ; i < points.size() ;i++) {
            auto it = points[i];
            double temp = (double)sqrt(  (it[0] * it[0])  +  (it[1] * it[1] )   );
            ans[temp].push_back(i)  ;
        }
        for(auto it : ans){
            if(!k)break;
            for(int i = 0 ; i < it.second.size() ;i++){
                anss.push_back(points[it.second[i]]) ;
            k--;

            }
        }
        return anss;
    }
};