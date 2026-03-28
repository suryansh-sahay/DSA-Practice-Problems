class Solution {
public:
    void func(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int> nums){
        if(target==0) {
            ans.push_back(arr);
            return;
        }
        else if(ind>nums.size()-1 || nums[ind]>target) return;
        arr.push_back(nums[ind]);
        func(ind, target-nums[ind], arr, ans, nums);
        arr.pop_back();
        func(ind+1, target, arr, ans, nums);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int ind=0;
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        func(ind, target, arr, ans, candidates);
        return ans;
    }
};