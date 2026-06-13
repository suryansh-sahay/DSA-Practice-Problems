class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1000000007;
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; 
        vector<int> last(26, -1); 

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            dp[i + 1] = dp[i] * 2 % MOD;

            if (last[c] >= 0)  dp[i + 1] = (dp[i + 1] - dp[last[c]] + MOD) % MOD;
            last[c] = i;
        }

        return (dp[n] - 1 + MOD) % MOD;
    }
};