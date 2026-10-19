
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> ans(m, vector<int>(n, -1));

        // Start BFS from every zero
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    ans[i][j] = 0;
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int row = front.first.first;
            int col = front.first.second;
            int dist = front.second;

            for (int k = 0; k < 4; k++) {
                int nrow = row + drow[k];
                int ncol = col + dcol[k];

                if (nrow >= 0 && nrow < m &&
                    ncol >= 0 && ncol < n &&
                    ans[nrow][ncol] == -1) {

                    ans[nrow][ncol] = dist + 1;
                    q.push({{nrow, ncol}, dist + 1});
                }
            }
        }

        return ans;
    }
};
