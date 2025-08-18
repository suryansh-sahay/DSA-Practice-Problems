class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // Special cases
        if (k == 0 || n >= k + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        double windowSum = 1.0;  // running sum of last maxPts valid dp values
        double ans = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = windowSum / maxPts;

            if (i < k) {
                // still drawing, contribute to future
                windowSum += dp[i];
            } else {
                // reached at least k points, game stops
                ans += dp[i];
            }

            // remove value that slides out of the window
            if (i - maxPts >= 0) {
                windowSum -= dp[i - maxPts];
            }
        }
        return ans;
    }
};
