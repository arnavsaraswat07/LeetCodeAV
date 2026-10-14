class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return INT_MAX;
        }

        if (i == 0 && j == 0) {
            return grid[0][0];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int up = solve(i - 1, j, grid, dp);
        int left = solve(i, j - 1, grid, dp);

        int best = min(up, left);

        return dp[i][j] = (best == INT_MAX)
                            ? INT_MAX
                            : grid[i][j] + best;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, grid, dp);
    }
};