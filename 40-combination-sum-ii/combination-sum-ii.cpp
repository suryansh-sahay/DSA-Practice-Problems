class Solution {
public:
    void func(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& nums){
        if(target==0) {
            ans.push_back(arr);
            return;
        }
        for(int i=ind; i<nums.size(); i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) return;
            arr.push_back(nums[i]);
            func(i+1, target-nums[i], arr, ans, nums);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        func(0, target, arr, ans, candidates);
        return ans;
    }
};