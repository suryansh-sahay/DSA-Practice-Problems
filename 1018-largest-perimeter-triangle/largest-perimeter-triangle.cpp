class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        for(int i=0; i<nums.size()-2; i++){
            int val=nums[i+1]+nums[i+2];
            if(nums[i]<val) return nums[i]+val;
        }
        return 0;
    }
};