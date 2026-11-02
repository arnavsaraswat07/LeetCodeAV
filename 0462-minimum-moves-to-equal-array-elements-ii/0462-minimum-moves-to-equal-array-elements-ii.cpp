class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //median tak laana hai
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid=nums[n/2];
        int count=0;
        for(int i:nums){
            count+=abs(i-mid);


        }
        return count;
        
    }
};