class Solution {
public: 
      pair< int , int > inttopos( int x    , int len){
        int r = (x - 1) / len  ;
        int c  =  ( x  - 1 ) %  len ;
        if (  r% 2  != 0 ){
            c =  len  -1-c ;
        }
        return make_pair(r , c) ;
      }

    int snakesAndLadders(vector<vector<int>>& board) {
        int len =  board.size() ;

        reverse(board.begin() , board.end()); 
        queue< pair<int  , int>> bfs  ;
        bfs.push(make_pair(1 , 0) ) ;
        set < int > vis ;
        while(!bfs.empty()) {
             pair< int  , int  > rc =  bfs.front() ;
             bfs.pop() ;
             int sq  =  rc.first ;
             int mv  =  rc.second;
              for( int i = 1  ; i < 7 ; i++) {
                  int nextsq =  sq + i ;
                   pair< int , int > r_c  = inttopos(nextsq , len ) ;
                   int r  =  r_c.first ;
                   int c  =  r_c.second ;
                  if(board[r][c] !=  -1 )
                  nextsq = board[r][c];
                  if(nextsq ==  len* len ) 
                  return mv + 1;
                  if(!vis.contains(nextsq)) {
                      vis.insert(nextsq) ;
                      bfs.push(make_pair(nextsq , mv+1)) ;
                  }
              }
        }
        return -1 ;
    }
};