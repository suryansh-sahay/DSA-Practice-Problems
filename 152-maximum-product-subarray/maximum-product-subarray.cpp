class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size()-1;
        int l=1, r=1, ans=INT_MIN;

        for(int i=0; i<=n; i++){
            l*=nums[i], r*=nums[n-i];
            ans=max({ans, l, r});
            if(l==0) l=1; 
            if(r==0) r=1;
        }
        return ans;
    }
};