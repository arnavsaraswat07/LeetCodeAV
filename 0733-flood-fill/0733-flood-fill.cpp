class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>&vis,int color,int c,int m,int n){
        image[row][col]=color;
        vis[row][col]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && image[nrow][ncol]==c){
                dfs(nrow,ncol,image,vis,color,c,m,n);

            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //initial color milega usko def karo
        //its calmmm
        int m=image.size();
        int n=image[0].size();
        int c=image[sr][sc];
        if(c==color){
            return image;
        }
        vector<vector<int>>vis(m,vector<int>(n,0));
        dfs(sr,sc,image,vis,color,c,m,n);
        return image;
        
    }
};