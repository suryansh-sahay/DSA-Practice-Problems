class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sum1 = 1, sum2 = 1, sum3 = 1, sum4 = 1; 
        int n = nums.size();
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            sum1 = max(sum1 * nums[i], nums[i]);
            sum2 *= nums[i];

            sum3 = max(sum3 * nums[n - 1 - i], nums[n - 1 - i]);
            sum4 *= nums[n - 1 - i];

            int temp1 = max(sum1, sum2);
            int temp2 = max(sum3, sum4);
            int temp = max(temp1, temp2);
            maxi = max(maxi, temp);
            if (sum2 == 0) sum2 = 1; 
            if (sum4 == 0) sum4 = 1; 
        }

        return maxi;
    }
};
