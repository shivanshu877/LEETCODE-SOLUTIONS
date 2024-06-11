class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int , int> ans1;
        for(int i = 0 ; i < arr1.size() ; i++ ){
            ans1[arr1[i]]++;
        }
            vector<int > un;
        for(auto it : arr2){
            while(ans1[it]){
                un.push_back(it);
                ans1[it]--;
                if(!ans1[it])ans1.erase(it);
            }
        }
        for(auto& it : ans1){
            int s =  it.second;
            for(int i =0 ; i < s ; i++){
                un.push_back(it.first);
            }
        }
        return un;
    }
};