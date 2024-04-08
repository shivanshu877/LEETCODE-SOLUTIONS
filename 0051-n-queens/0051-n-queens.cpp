#include<bits/stdc++.h>
class Solution {
public:
    
     bool isSafe1(int row, int col, vector < string > board, int n) {
      // check upper element
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }

    void f(int n , int idx , vector<string>& ans ,    vector<vector<string>>& a) {
        if(idx == n ){
        a.push_back(ans);
            return  ;
        }
        for(int i = 0 ; i < n ;i++) {
            if (isSafe1(i, idx, ans, n)) {
          ans[i][idx] = 'Q';
          f(n,  idx+1, ans,a);
          ans[i][idx] = '.';
        }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> a;

         vector<string> ans (n  );
        string s (n , '.');
        for(int i = 0 ; i < n ;i++)ans[i] = s;
        f(n, 0 , ans ,a) ;
        return a; 
    }
};