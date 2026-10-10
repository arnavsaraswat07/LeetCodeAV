class Solution {
public:
    int solve(vector<int>& prices, int index, int hold,
          vector<vector<int>>& dp){
        if(index==prices.size()){
            return 0;
        }
        if (dp[index][hold] != -1)
            return dp[index][hold];
        if(hold==0){
            int buy=max(-prices[index]+solve(prices,index+1,1,dp),solve(prices,index+1,0,dp));
            return dp[index][hold]=buy;

        }
        else{
            int nobuy=max(+prices[index]+solve(prices,index+1,0,dp),solve(prices,index+1,1,dp));
            return dp[index][hold]=nobuy;


        }
        
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int index=prices.size()-1;
        int hold=0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(prices,0,hold,dp);

        
    }
};