class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
sort(intervals.begin(),intervals.end(),[](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });          vector<pair<int , int>> ans;
        ans.push_back({intervals[0][0] , intervals[0][1] }) ;
        int a =0 ;
        for(int i =1 ; i < intervals.size() ; i++){
            if(ans.back().second > intervals[i][0] ){
                a++;
            }
            else { 
                ans.push_back({intervals[i][0] , intervals[i][1] })  ;         
            }    
        }
        return a ;
        
//           int ans=-1;      
// 		if(intervals.size()==0) return 0;       
// 		sort(intervals.begin(),intervals.end(),[](const vector<int>& a, const vector<int>& b){
//             return a[1] < b[1];
//         });     
// 		vector<int> prev= intervals[0];

// 		for(vector<int> i: intervals) {
// 			if(prev[1]>i[0]) {
// 				ans++;              
// 			}else prev=i;          
// 		}
// 		return ans; 
    }
};