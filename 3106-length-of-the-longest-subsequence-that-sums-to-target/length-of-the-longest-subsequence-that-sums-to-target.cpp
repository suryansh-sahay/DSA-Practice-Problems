class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target){
        vector<int> dp(target+1,0);
        for(int num : nums) 
            for(int t=target;t>=num;t--) 
                if(t-num == 0 || dp[t-num]) 
                    dp[t] = max(dp[t],1+dp[t-num]);
        return dp[target] ? dp[target] : -1;
    }
};