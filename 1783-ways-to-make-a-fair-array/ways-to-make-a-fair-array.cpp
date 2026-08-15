class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int be = 0, bo = 0, ae = 0, ao = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (i % 2 == 0) ae += nums[i];
            else ao += nums[i];

        int count = 0;
        for (int i = 0; i < n; i++) {
            int even;
            int odd;
            int curr = nums[i];
            if (i % 2 == 0) {
                even = be + ao;
                odd = bo + ae - curr;

                be += curr;
                ae -= curr;
            } else {
                even = be + ao - curr;
                odd = bo + ae;

                bo += curr;
                ao -= curr;
            }
            if (even == odd) count++;
        }
        return count;
    }
};