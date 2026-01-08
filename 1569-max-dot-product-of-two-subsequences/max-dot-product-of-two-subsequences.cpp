class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        vector<vector<int>> dp(n, vector<int>(m));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int prod = nums1[i]*nums2[j];

                int cmax = prod;
                if(i>0 && j>0){
                    cmax = max(cmax, cmax+dp[i-1][j-1]);
                }

                if(i>0) cmax = max(cmax, dp[i-1][j]);
                if(j>0) cmax = max(cmax, dp[i][j-1]);

                dp[i][j] = cmax;
            }
        }

        return dp[n-1][m-1];
    }
};