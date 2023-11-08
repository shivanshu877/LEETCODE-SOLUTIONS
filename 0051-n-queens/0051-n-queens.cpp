class Solution
{
    public:

        void solve(int col, vector<string> &board, vector<vector< string >> &ans, int n, vector< int >& lr, vector< int >& ud, vector< int >& ld)
        {
            if (col == n)
            {
                ans.push_back(board);
                return;
            }

            for (int row = 0; row < n; row++)
            {
                if ( lr[row] == 0 && ld[row + col] == 0 && ud[n - 1 + col - row] == 0
               )
                {
                    board[row][col] = 'Q';
                    lr[row] = 1;
                    ld[row + col] = 1;
                    ud[n - 1 + col - row] = 1;
                    solve(col + 1, board, ans, n, lr, ud, ld);
                    board[row][col] = '.';
                    lr[row] = 0;
                    ld[row + col] = 0;
                    ud[n - 1 + col - row] = 0;

                    board[row][col] = '.';
                }
            }
        }

    vector<vector < string>> solveNQueens(int n)
    {
        string x = "";
        for (int j = 0; j < n; j++)
        {
            x += '.';
        }
        vector<string> board(n, x);
        vector<vector < string>> ans;
        vector<int> lr(n, 0);
        vector<int> ud(2 *n - 1, 0);
        vector<int> ld(2 *n - 1, 0);
        solve(0, board, ans, n, lr, ud, ld);
        return ans;
    }
};