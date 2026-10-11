class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int l = 0, r = n - 1;

        while (l < r && colors[l] == colors[r]) {
            l++;
        }

        int ans = r - l;

        l = 0;
        r = n - 1;

        while (l < r && colors[l] == colors[r]) {
            r--;
        }

        ans = max(ans, r - l);
        return ans;
    }
};