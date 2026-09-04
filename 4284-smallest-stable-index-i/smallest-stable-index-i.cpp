class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int mini[100];

        int n = nums.size();
        mini[n - 1] = nums.back();

        for (int i = n - 2; i >= 0; i--) mini[i] = min(nums[i], mini[i + 1]);

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            if (maxi - mini[i] <= k) return i;
        }
        return -1;    
    }
};