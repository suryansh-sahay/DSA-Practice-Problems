class Solution {
private:
    void func(int i, int t, vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans){
        if(i==nums.size()){
            if(t==0) ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        if(nums[i]<=t) func(i+1, t-nums[i], ds, nums, ans);

        while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
        ds.pop_back();
        func(i+1, t, ds, nums, ans);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());

        func(0, target, ds, candidates, ans);
        return ans;
    }
};