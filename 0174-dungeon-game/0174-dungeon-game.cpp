class Solution {
public:
    int solve(vector<vector<int>>&dungeon,int i,int j,vector<vector<int>>&dp){
        int m=dungeon.size();
        int n=dungeon[0].size();
        if(i==m-1 && j==n-1){
            return max(1,1-dungeon[m-1][n-1]);
        }
        if (i >= m || j >= n)
            return INT_MAX / 2;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right = solve(dungeon, i, j+1,dp);
        int down  = solve(dungeon, i+1, j,dp);

        return dp[i][j]=max(1, min(right, down) - dungeon[i][j]);
        

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(dungeon,0,0,dp);
        
    }
};