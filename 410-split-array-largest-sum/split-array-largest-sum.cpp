class Solution {
public:
    bool isValid(vector<int>& nums, int k, int mid) {
        int cnt = 1, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(sum+nums[i] > mid) {
                cnt++;
                sum = 0;
            }
            sum += nums[i];
        }
        return k >= cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = nums[0], r = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            l = max(l, nums[i]);
            r += nums[i];
        }
        while(l < r) {
            int mid = l + (r-l)/2;
            if(isValid(nums, k, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};