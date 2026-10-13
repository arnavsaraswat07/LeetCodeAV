class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long plus = 0;
        long long minus = 0;

        for (int x : nums) {
            long long newPlus = max(plus, minus + x);
            long long newMinus = max(minus, plus - x);

            plus = newPlus;
            minus = newMinus;
        }

        return plus;
    }
};