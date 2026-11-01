class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> mp;

        long long prefix = 0;
        long long count = 0;

        mp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];

            count += mp[prefix - k];

            mp[prefix]++;
        }

        return count;
    }
};
