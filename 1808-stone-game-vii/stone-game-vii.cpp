class Solution {
    vector<vector<int>> dp;
    vector<int> pref;

public:
    int solve(int left, int right) {
        if (left >= right) {
            return 0;
        }
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        return dp[left][right] = max(
                   pref[right + 1] - pref[left + 1] - solve(left + 1, right),
                   pref[right] - pref[left] - solve(left, right - 1));
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        dp.assign(n, vector<int>(n, -1));
        pref.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + stones[i];
        }
        return solve(0, n - 1);
    }
};