class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>curr(n,0),front(n,0);

        for (int j = 0; j < n; j++) {
            front[j] = matrix[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int down = front[j];
                int left = (j > 0) ? front[j - 1] : INT_MAX;
                int right = (j + 1 < n) ? front[j + 1] : INT_MAX;

                curr[j]= matrix[i][j] + min(down, min(left, right));
            }
            front=curr;
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, front[j]);
        }

        return ans;
    }
};