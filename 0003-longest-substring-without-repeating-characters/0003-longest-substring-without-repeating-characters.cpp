class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=0;
        unordered_map<char,int>mp;
        int l=0;
        int r=0;
        int n=s.size();
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            length=max(length,r-l+1);
            r++;
        }
        return length;
        
    }
};