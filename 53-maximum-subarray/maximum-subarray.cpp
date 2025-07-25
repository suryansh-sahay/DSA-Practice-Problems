class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int  maxi=nums[0], currSum=nums[0];
      for(int i=1; i<nums.size(); i++){
        currSum=max(nums[i], currSum+nums[i]);
        maxi=max(maxi, currSum);
      }
      return maxi;
    }
};