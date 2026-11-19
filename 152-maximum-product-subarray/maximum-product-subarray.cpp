class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pro1=1, pro2=1;
        int ans=nums[0];
        for(int i=0; i<n; i++){
            pro1*=nums[i], pro2*=nums[n-1-i];
            ans=max({ans, pro1, pro2});
            if(pro1==0) pro1=1;
            if(pro2==0) pro2=1;
        }
        return ans;
    }
};