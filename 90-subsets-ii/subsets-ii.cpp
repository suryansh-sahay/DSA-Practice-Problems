class Solution {
private: 
    void func(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds){
        if(idx==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        func(idx+1, nums, ans, ds);

        while(idx<nums.size()-1 && nums[idx]==nums[idx+1]) idx++;
        ds.pop_back();
        func(idx+1, nums, ans, ds);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        func(0, nums, ans, ds);
        return ans;
    }
};