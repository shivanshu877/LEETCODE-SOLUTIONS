class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int time = 0 ;
        vector<int> ans(t.size());
        queue<int> q ;
        for(int i  = 0 ;i < t.size() ;i++){
            q.push(i);
        }
        while(!q.empty()){
            time++;
            auto x = q.front();
            q.pop();
            int total =  t[x];
            t[x]--;
            if(t[x] == 0){
                ans[x] = time;
            }
            else{
                q.push(x);
            }
            
        }
        return ans[k];
    }
};