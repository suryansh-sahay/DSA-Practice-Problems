class Solution {
private: 
    void func(int i, vector<int>& nums, vector<vector<int>>& ans){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int idx=i; idx<nums.size(); idx++){
            swap(nums[i], nums[idx]);
            func(i+1, nums, ans);
            swap(nums[i], nums[idx]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        func(0, nums, ans);
        return ans;
    }
};