class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        // int j = 0;
        // int temp = nums[j];
        // for (int i = 0; i < n; i++) {
        //     j = (j + k) % n;
        //     int temp1 = nums[j];
        //     nums[j] = temp;
        //     temp = temp1;
        // }
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};