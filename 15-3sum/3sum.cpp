class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        // int i=0,j=1,k=n-1;  
        vector<vector<int>> ans;

        for(int i = 0 ; i < n-2 ; ++i){
            // int currSum = nums[i];
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(nums[j] + nums[k] + nums[i] < 0){
                    j++;
                }
                else if(nums[j] + nums[k]+ nums[i]> 0){
                    k--;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(k > j && nums[k] == nums[k+1]) k--;
                }
            }
            // i++;

        }   
        return ans;   
    }
}; 