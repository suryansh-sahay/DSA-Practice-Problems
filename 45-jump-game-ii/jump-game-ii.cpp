class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0, n=nums.size();
        int l=0, r=0;
        while(r<n-1){
            int maxi=0;
            for(int i=l; i<=r; i++) maxi=max(maxi, i+nums[i]);
            l=r+1, r=maxi, ans++;
        }
        return ans;
    }
};