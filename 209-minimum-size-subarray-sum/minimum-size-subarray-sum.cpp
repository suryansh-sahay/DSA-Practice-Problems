class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        long curr_sum=0;
        int min_size=INT_MAX;
        for(int r=0;r<nums.size();r++){
             curr_sum+=nums[r];
             while(curr_sum>=target){
                min_size=min(min_size,r-l+1);
                curr_sum-=nums[l];
                l++;
             }
        }
        return (min_size==INT_MAX) ? 0:min_size;
    }
};