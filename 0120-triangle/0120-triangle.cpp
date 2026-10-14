class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {

        int n = triangle.size();

        if (i == n - 1) {
            return triangle[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = solve(i + 1, j, triangle, dp);
        int right = solve(i + 1, j + 1, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(down, right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int down =dp[i+1][j];
                int right = dp[i+1][j+1];

                dp[i][j] = triangle[i][j] + min(down, right);
            }
        }
        return dp[0][0];

        
    }
};