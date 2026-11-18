class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);

        int p=0, m=1;
        for(int num: nums){
            if(num>0) ans[p]=num, p+=2;
            else ans[m]=num, m+=2;
        }
        return ans;
    }
};