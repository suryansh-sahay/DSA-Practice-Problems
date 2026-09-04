class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            long long prdt = 1;
            long long lcmm = 1;
            int gcdd = 0;

            for (int j = i; j < nums.size(); j++) {
                prdt *= nums[j];
                if (prdt > 36288000) break;

                lcmm = lcm(lcmm, (long long)nums[j]);
                gcdd = gcd(gcdd, nums[j]);

                if (prdt == lcmm * gcdd) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};