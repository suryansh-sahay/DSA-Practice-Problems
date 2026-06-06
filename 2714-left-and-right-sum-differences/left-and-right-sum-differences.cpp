class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int r=accumulate(nums.begin(), nums.end(), 0), l=0;
        
        for(int i=0; i<nums.size(); i++){
            int temp=nums[i];
            r-=temp;
            nums[i]=abs(l-r);
            l+=temp;
        }
        return nums;
    }
};