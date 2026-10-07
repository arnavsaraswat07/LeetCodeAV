class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int index=coins.size()-1;
        vector<vector<long>>dp(index+1,vector<long>(amount+1,0));
        for(int c=0;c<=amount;c++){
            if(c % coins[0] == 0)
                dp[0][c] = 1;
            else
                dp[0][c] = 0;

        }
        
        
        for(int i=0;i<=index;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=index;i++){
            for(int c=0;c<=amount;c++){
                long notake=dp[i-1][c];
                long take=0;
                if(coins[i]<=c){
                    take=dp[i][c-coins[i]];
            
                }
                if(take>INT_MAX-notake){
                    dp[i][c]=INT_MAX;
                }
                else{
                    dp[i][c]=take+notake;
                }

            }
            

        }
        return dp[index][amount];


        
    }
};