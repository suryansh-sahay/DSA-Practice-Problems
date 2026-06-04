class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0;
        int right=0;
        int maxLen=0;        
        while(right<n){
            while(nums[right]-nums[left]>1){
                left++;
            }
            if(nums[right]-nums[left]==1){
                maxLen=max(maxLen, right-left+1);
            }
            right++;
        }
        return maxLen;        
    }
};