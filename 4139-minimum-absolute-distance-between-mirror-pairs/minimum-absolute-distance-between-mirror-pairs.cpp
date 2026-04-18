class Solution {
public:
    int reverseNum(int n) {
        int t = 0;
        while (n > 0) {
            t *= 10;
            t += n % 10;
            n /= 10;
        }
        return t;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        int n = nums.size();
        mp[nums[n - 1]] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            int rev = reverseNum(nums[i]);

            if (mp.find(rev) != mp.end()) {
                int j = mp[rev];
                ans = min(ans, j - i);
            }

            mp[nums[i]] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};