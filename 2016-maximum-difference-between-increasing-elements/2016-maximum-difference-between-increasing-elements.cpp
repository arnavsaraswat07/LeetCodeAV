class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        //scan right to left and keep track of max element u encounter and then the min element and then do a check tht the max shd come before the min

        //but tht wont work  ig
        int n=nums.size();
        int maxright=INT_MIN;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            maxright=max(maxright,nums[i]);
            //ab maxright calc ho gaya now
            if(nums[i]<maxright){
                ans=max(ans,maxright-nums[i]);
            }


        }
        if(ans==0){
            return -1;
        }
        return ans;
    }
};