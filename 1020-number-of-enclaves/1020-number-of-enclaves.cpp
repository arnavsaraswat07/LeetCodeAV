class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid,
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
                grid[nrow][ncol] == 1) {

                dfs(nrow, ncol, grid, vis, m, n);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Traverse the first and last columns
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && !vis[i][0])
                dfs(i, 0, grid, vis, m, n);

            if (grid[i][n - 1] == 1 && !vis[i][n - 1])
                dfs(i, n - 1, grid, vis, m, n);
        }

        // Traverse the first and last rows
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1 && !vis[0][j])
                dfs(0, j, grid, vis, m, n);

            if (grid[m - 1][j] == 1 && !vis[m - 1][j])
                dfs(m - 1, j, grid, vis, m, n);
        }

        // Count land cells not connected to the boundary
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j])
                    count++;
            }
        }

        return count;
    }
};