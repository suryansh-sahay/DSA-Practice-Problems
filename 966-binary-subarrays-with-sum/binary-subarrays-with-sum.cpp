int atMost(vector<int>& nums, int goal) {
    if (goal < 0) return 0;
    int l = 0, sum = 0, ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        while (sum > goal) {
            sum -= nums[l++];
        }
        ans += i - l + 1;
    }
    return ans;
}

class Solution{
    public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};