class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> vals(nums.begin(), nums.end());

        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int val: nums){
            mini=min(val, mini);
            maxi=max(val, maxi);
        }
        vector<int> ans;
        for(int i=mini; i<=maxi; i++){
            if(!vals.count(i)) ans.push_back(i);
        }
        return ans;
    }
};