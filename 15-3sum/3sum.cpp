class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n=nums.size();
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1, k=n-1;
            while(j<k){
                int temp=nums[i]+nums[j]+nums[k];
                if(temp<0) j++;
                else if(temp>0) k--;
                else {
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;                  
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                }
            }
        }
        return ans;
    }
};