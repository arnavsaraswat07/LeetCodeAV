class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;
        int maxsum = 0;

        int n = cardPoints.size();

        // Initially take all k cards from the left
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }

        maxsum = lsum;

        // Start taking cards from the right
        int rindex = n - 1;

        // Replace left cards one by one with right cards
        for (int i = k - 1; i >= 0; i--) {
            lsum -= cardPoints[i];
            rsum += cardPoints[rindex];

            maxsum = max(maxsum, lsum + rsum);

            rindex--;
        }

        return maxsum;
    }
};