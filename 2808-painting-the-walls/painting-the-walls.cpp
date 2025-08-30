class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        const int INF = 1e9;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;  // Base case: cost to paint 0 walls is 0

        for (int i = 0; i < n; ++i) {
            for (int j = n; j >= 0; --j) {
                int k = min(n, j + time[i] + 1); // how many walls this paid painter can cover
                dp[k] = min(dp[k], dp[j] + cost[i]);
            }
        }

        return dp[n];
    }
};