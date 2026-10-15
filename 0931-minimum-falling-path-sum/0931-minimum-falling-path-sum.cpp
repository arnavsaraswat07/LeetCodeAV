class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix,
              vector<vector<int>>& dp) {
        int n = matrix.size();

        if (j < 0 || j >= n) {
            return INT_MAX;
        }

        if (i == n - 1) {
            return matrix[i][j];
        }

        if (dp[i][j] != INT_MIN) {
            return dp[i][j];
        }

        int down = solve(i + 1, j, matrix, dp);
        int left = solve(i + 1, j - 1, matrix, dp);
        int right = solve(i + 1, j + 1, matrix, dp);

        int best = min(down, min(left, right));

        return dp[i][j] = (best == INT_MAX)
                            ? INT_MAX
                            : matrix[i][j] + best;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {
            ans = min(ans, solve(0, j, matrix, dp));
        }

        return ans;
    }
};