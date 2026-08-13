class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int ss = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1] + 1) ss += nums[i];
            else break;
        }

        vector<bool> ht(1276, false);
        
        for(int num : nums) ht[num] = true;
        while(ht[ss]) ss++;

        return ss;
    }
};