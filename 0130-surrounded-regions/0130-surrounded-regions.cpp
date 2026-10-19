
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board,
             vector<vector<int>>& vis, int m, int n) {

        vis[i][j] = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];

            if (nrow >= 0 && nrow < m &&
                ncol >= 0 && ncol < n &&
                !vis[nrow][ncol] &&
                board[nrow][ncol] == 'O') {

                dfs(nrow, ncol, board, vis, m, n);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Run DFS from boundary O's
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !vis[i][0])
                dfs(i, 0, board, vis, m, n);

            if (board[i][n - 1] == 'O' && !vis[i][n - 1])
                dfs(i, n - 1, board, vis, m, n);
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !vis[0][j])
                dfs(0, j, board, vis, m, n);

            if (board[m - 1][j] == 'O' && !vis[m - 1][j])
                dfs(m - 1, j, board, vis, m, n);
        }

        // Flip unvisited O's to X
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
