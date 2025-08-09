class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> check;
        check.reserve(nums.size());
        for (int num : nums)
            check.insert(num);

        int ans = 0;
        for (int num : check) {
            if (!check.count(num - 1)) {
                int leng = 1, current = num;
                while (check.count(current + 1)) {
                      leng++, current++;
                }
                ans = max(ans, leng);
            }
        }
        return ans;
    }
};