class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, temp=0, ans=0;
        for(int j=0; j<nums.size(); j++){
            if(nums[j]==0) k--;
            temp++;
            if(k<0){
                while(nums[i]==1) temp--, i++;
                temp--, k++, i++;
            }
            ans=max(ans, temp);
        }
        return ans;
    }
};