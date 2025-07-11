class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int decrease=0;
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1]) decrease++;
        }
        if(nums[n-1]>nums[0]) decrease++;

    return decrease<=1;
    }
};