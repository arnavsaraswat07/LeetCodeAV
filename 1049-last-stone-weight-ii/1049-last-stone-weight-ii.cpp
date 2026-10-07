class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int total=0;
        for(int i:stones){
            total+=i;
        }
        int target=total/2;

        vector<vector<int>>dp(n,vector<int>(target+1,0));

        for(int i=0;i<n;i++){
            dp[i][0]=true;

        }
        if(stones[0]<=target){
            dp[0][stones[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool notake=dp[i-1][j];
                bool take=false;
                if(stones[i]<=j){
                    take=dp[i-1][j-stones[i]];
                }

                dp[i][j]=take||notake;
            }

        }
        int best=0;
        for(int sum=target;sum>=0;sum--){
            if(dp[n-1][sum]){
                best=sum;
                break;
            }
        }

        return total-2*best;
        
    }
};