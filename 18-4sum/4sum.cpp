class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());

        for(int s=0; s<n-3; s++){
            if(s>0&&nums[s]==nums[s-1]) continue;
        for (int i = s+1; i < n - 2; i++) {
            if (i>s+1 && nums[i]==nums[i-1]) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                long long temp = (long long)nums[s]+nums[i] + nums[j] + nums[k];
                if (temp < target)
                    j++;
                else if (temp > target)
                    k--;
                else {
                    answer.push_back({nums[s], nums[i], nums[j], nums[k]});
                    while( j<k && nums[j]==nums[j+1]) j++;
                    while( j<k && nums[k]==nums[k-1]) k--;
                    j++, k--;
                }
            }
        } }
        return answer;
    }
};