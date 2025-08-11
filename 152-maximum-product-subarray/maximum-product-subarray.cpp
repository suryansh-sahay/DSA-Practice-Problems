class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int fwrd = 1, bkwd = 1;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            fwrd *= nums[i];
            bkwd *= nums[n - 1 - i];
            maxi = max({maxi, fwrd, bkwd});
            if(fwrd==0) fwrd=1;
            if(bkwd==0) bkwd=1;
        }
        return maxi;
    }
};
