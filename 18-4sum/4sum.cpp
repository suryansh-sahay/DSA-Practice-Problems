class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n=nums.size();
        for(int m=0; m<n-3; m++){
            if(m>0 && nums[m]==nums[m-1]) continue;
            for(int i=m+1; i<n-2; i++){
                if(i>m+1 && nums[i]==nums[i-1]) continue;
                int j=i+1, k=n-1;
                while(j<k){
                    long long temp=(long long)nums[m]+nums[i]+nums[j]+nums[k];
                    if(temp<target) j++;
                    else if(temp>target) k--;
                    else {
                        while(j<k && nums[j]==nums[j+1]) j++;
                        while(j<k && nums[k]==nums[k-1]) k--;  
                        ans.push_back({nums[m], nums[i], nums[j], nums[k]});
                        j++, k--;
                    }
                }
            }
        }
        return ans;
    }
};

