class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //basically k zeroes allowed hai
        //its calmmm
        int l=0;
        int r=0;
        int maxlen=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp[0]>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                    
                }
                l++;  
                
            }
            maxlen=max(maxlen,r-l+1);
            r++;

        }
        return maxlen;
        
    }
};