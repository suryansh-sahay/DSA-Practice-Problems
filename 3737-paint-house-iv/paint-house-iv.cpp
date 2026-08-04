class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        int half = n / 2;
        vector<long long> dp(6, 0), temp(6, 0); 
        dp[0] = cost[0][0] + cost[n-1][1]; 
        dp[1] = cost[0][0] + cost[n-1][2]; 
        dp[2] = cost[0][1] + cost[n-1][2]; 
        dp[3] = cost[0][1] + cost[n-1][0]; 
        dp[4] = cost[0][2] + cost[n-1][0]; 
        dp[5] = cost[0][2] + cost[n-1][1]; 

        for (int i = 1; i < half; ++i) {
            temp[0] = min({dp[2], dp[3], dp[4]}) + cost[i][0] + cost[n-i-1][1]; 
            temp[1] = min({dp[3], dp[4], dp[5]}) + cost[i][0] + cost[n-i-1][2]; 
            temp[2] = min({dp[0], dp[4], dp[5]}) + cost[i][1] + cost[n-i-1][2]; 
            temp[3] = min({dp[0], dp[1], dp[5]}) + cost[i][1] + cost[n-i-1][0]; 
            temp[4] = min({dp[0], dp[1], dp[2]}) + cost[i][2] + cost[n-i-1][0]; 
            temp[5] = min({dp[1], dp[2], dp[3]}) + cost[i][2] + cost[n-i-1][1]; 
            dp = temp; 
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};