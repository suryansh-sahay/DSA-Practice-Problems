class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0, result=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]) ans++;
            else ans=0;
            result=max(result, ans);
        }
        return result;
    }
};