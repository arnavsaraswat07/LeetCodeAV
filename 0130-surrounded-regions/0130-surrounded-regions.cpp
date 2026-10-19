
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board,
             int m, int n) {

        board[i][j] = '#';  // Temporarily protect this O

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];

            if (nrow >= 0 && nrow < m &&
                ncol >= 0 && ncol < n &&
                board[nrow][ncol] == 'O') {

                dfs(nrow, ncol, board, m, n);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // DFS from boundary O's
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, board, m, n);

            if (board[i][n - 1] == 'O')
                dfs(i, n - 1, board, m, n);
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                dfs(0, j, board, m, n);

            if (board[m - 1][j] == 'O')
                dfs(m - 1, j, board, m, n);
        }

        // Flip surrounded O's and restore protected cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
