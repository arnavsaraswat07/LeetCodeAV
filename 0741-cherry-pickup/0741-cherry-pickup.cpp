class Solution {
public:
    int solve(vector<vector<int>>&grid,int r1,int c1,int r2,vector<vector<vector<int>>>&dp){
        int n=grid.size();
        int c2=r1+c1-r2;
        if(c1<0 || c1>=n || r1>=n || r1<0 || c2>=n || c2<0 || r2>=n || r2<0){
            return INT_MIN/2;

        }
        if(grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return INT_MIN/2;
        }
        if(r1==n-1 && c1==n-1){
            return grid[r1][c1];
        }
        if(dp[r1][c1][r2]!=-1){
            return dp[r1][c1][r2];
        }
        int cherries=grid[r1][c1];
        if(r1!=r2 || c1!=c2){
            cherries+=grid[r2][c2];
        }
        int best=max(max(solve(grid,r1+1,c1,r2+1,dp),solve(grid,r1+1,c1,r2,dp)),max(solve(grid,r1,c1+1,r2+1,dp),solve(grid,r1,c1+1,r2,dp)));

        return dp[r1][c1][r2]=cherries+best;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();

vector<vector<vector<int>>> dp(
    n, vector<vector<int>>(n, vector<int>(n, -1))
);
        return max(0,solve(grid,0,0,0,dp));
        
    }
};