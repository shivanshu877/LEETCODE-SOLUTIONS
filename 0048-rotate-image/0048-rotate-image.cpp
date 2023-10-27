class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> a ;
        vector<int> temp;
        int x = matrix.size();
        int count =0 ; 
        for(int i = 0  ; i< matrix.size() ;i++){
            for(int j = matrix.size()-1 ; j  >=0  ; j--){
            temp.push_back({matrix[j][i]});
            }
            a.push_back(temp);
            temp.clear();
            count++;
            if(count == x)
            break;
            
        }
               matrix.clear();
         for (int i=0; i<a.size(); i++) 
        matrix.push_back(a[i]); 
        
    }
};