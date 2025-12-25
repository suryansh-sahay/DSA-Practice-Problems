class Solution {
public:
    int maximizeWin(vector<int>& a, int k) {
        int n = a.size();
        vector<int> dp(n+1);
        int l=0 , r=0 ;
        int ans = 0 ;
        while(r<n) {
            while(a[r] - a[l] > k) {
                l++;
            }
            dp[r+1] = max(dp[r] , r-l+1);
            ans = max(ans , dp[l] + r-l+1);
            r++;
        }
        return ans ;
    }
};