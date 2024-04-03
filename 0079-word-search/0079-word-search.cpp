class Solution {
public:
    bool ans(string word  , vector<vector<char>>&  board ,  int m , int n , int i , int j  ,int idx) {
        if(  i >= m ||  j >= n || i < 0  || j < 0  || idx >= word.size() || board[i][j] != word[idx])return false;
         if (idx == word.size() - 1 && board[i][j] == word[idx])
        return true;
        vector<pair<int , int>> dir{{-1,0} , {0,-1}  , {1 , 0}  , {0 , 1} } ;
        char temp = board[i][j] ;
        board[i][j] = '0' ;
        for(auto it : dir){
         if(ans(word , board , m , n ,it.first + i  , it.second +j  , idx+1 ))return true;
        }
        
        board[i][j] = temp ;
        return false ;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0 ; i < board.size() ; i++ ){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == word[0])
             if(ans(word , board , board.size() , board[0].size() ,  i  , j , 0 ) ==  true)return true ;
            }
        }
        return false;
    }
};