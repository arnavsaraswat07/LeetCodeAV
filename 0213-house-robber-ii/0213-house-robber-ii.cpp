class Solution {
public:
    int solve(vector<int>nums,int l,int r){
        
        //base case done
        //now we need to see for the dp
        //take not take
        int len=r-l+1;
        if(len==1){
            return nums[l];
        }
        vector<int>dp(len,0);
        dp[0]=nums[l];
        dp[1]=max(nums[l],nums[l+1]);
        for(int i=2;i<len;i++){
            int nottake=dp[i-1];
            int take=nums[l+i]+dp[i-2];
            dp[i]=max(take,nottake);
        }
        return dp[len-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        return max(solve(nums,0,n-2),solve(nums,1,n-1));
        
        
    }
};