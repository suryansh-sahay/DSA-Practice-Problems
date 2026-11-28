class Solution {
private: 
    void func(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds){
        if(idx==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        func(idx+1, nums, ans, ds);

        ds.pop_back();
        func(idx+1, nums, ans, ds);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        func(0, nums, ans, ds);
        return ans;
    }
};