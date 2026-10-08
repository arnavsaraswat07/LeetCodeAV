class Solution {
public:
    int minDistance(string word1, string word2) {
        int i=word1.size();
        int j=word2.size();
        if(i==0){
            return j;
        }
        if(j==0){
            return i;
        }
        vector<vector<int>>dp(i+1,vector<int>(j+1,0));

        for(int n=0;n<=i;n++){
            dp[n][0]=n;
        }
        for(int m=0;m<=j;m++){
            dp[0][m]=m;
        }

        for(int index1=1;index1<=i;index1++){
            for(int index2=1;index2<=j;index2++){
                if(word1[index1-1]==word2[index2-1]){
                    dp[index1][index2]=dp[index1-1][index2-1];
                }
                else{
                    dp[index1][index2]=1+min(dp[index1][index2-1],min(dp[index1-1][index2],dp[index1-1][index2-1]));
                }
            }
        }
        return dp[i][j];
        
    }
};