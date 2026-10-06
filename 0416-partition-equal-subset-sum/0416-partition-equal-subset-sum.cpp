class Solution {
public:
//ly insh
    bool solve(vector<int>nums,int index,int target,vector<vector<int>>&dp){
        if(index==0){
            return nums[0]==target;

        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int notake=solve(nums,index-1,target,dp);
        int take=0;
        if(nums[index]<=target){
            take=solve(nums,index-1,target-nums[index],dp);
        }
        return dp[index][target]=take|| notake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int index=n-1;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];

        }
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        for(int i=0;i<n;i++){
            if(nums[0]<=target){
                dp[0][nums[0]]=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int sum=0;sum<=target;sum++){
                bool notake=dp[i-1][sum];
                bool take=0;
                if(nums[i]<sum){
                    take=dp[i-1][sum-nums[i]];
                }
                dp[i][sum]=take||notake;

            }

        }
        
        return dp[n-1][target];
        
    }
};