class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0, curr=0, maxi=0;
        
        for(int i=0; i<nums.size()-1; i++){
            maxi=max(maxi, i+nums[i]);
            if(i==curr) ans++, curr=maxi;
        }
        return ans;
    }
};