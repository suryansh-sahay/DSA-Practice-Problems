class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int val1 = nums[0];
        int val2 = max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++){
            int val3 = max(val1+nums[i],val2);
            val1 = val2;
            val2 = val3;
        }
        int ans1 = val2;

        val1 = nums[1];
        val2 = max(nums[1],nums[2]);
        for(int i=3;i<n;i++){
            int val3 = max(val1+nums[i],val2);
            val1 = val2;
            val2 = val3;
        }
        int ans2 = val2;
        return max(ans2,ans1);
    }
};