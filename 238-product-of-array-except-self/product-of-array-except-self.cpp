class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer(n,1);
         
        int fwrd=1, bkwd=1;
        for(int i=0; i<n; i++){
           answer[i]*=fwrd, fwrd*=nums[i];
           answer[n-1-i]*=bkwd, bkwd*=nums[n-1-i];
        }
        return answer;
    }
};