class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> preSum;
        for(int i=0; i<nums.size(); i++){
            if(preSum.find(target-nums[i]) != preSum.end()) return {i, preSum[target-nums[i]]};
            preSum[nums[i]]=i;
        }
        return {};
    }
};