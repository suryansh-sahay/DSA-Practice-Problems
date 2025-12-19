class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> boundaries(2 * limit + 2, 0);  
        int left = 0, right = n - 1;
        while (left < right) {
            int lower = min(nums[left], nums[right]);
            int higher = max(nums[left], nums[right]);

            int mn = lower + 1;
            int mx = higher + limit;

            boundaries[2] += 2;
            boundaries[mn] -= 1;

            boundaries[nums[left] + nums[right]] -= 1;
            boundaries[nums[left] + nums[right] + 1] += 1;

            boundaries[mx + 1] += 1;

            left += 1;
            right -= 1;
        }

        int res = INT_MAX;
        int num_to_change = 0;
        for (int i = 2; i < boundaries.size(); i += 1) {
            num_to_change += boundaries[i];
            res = min(res, num_to_change);
        }

        return res;
    }
};