class Solution {
public:
    bool isPalindromic(long long x) {
        long long original = x;
        long long reversed = 0;

        while (x > 0) {
            long long digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }
        return original == reversed;
    }
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long n = nums.size();

        long long mid = nums[n / 2];
        long long incMid = mid;
        long long decMid = mid;

        while (!isPalindromic(incMid))
            incMid++;
        while (!isPalindromic(decMid))
            decMid--;
        long long costInc = 0, costDec = 0;
        for (long long i = 0; i < n; ++i) {
            costInc += abs(nums[i] - incMid);
            costDec += abs(nums[i] - decMid);
        }
        return min(costInc, costDec);
    }
};