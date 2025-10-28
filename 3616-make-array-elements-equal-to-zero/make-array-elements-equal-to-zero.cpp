class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        
        int temp=0, ans=0;
        for(int num: nums){
            temp+=num;
            if(num==0){
                if(sum==2*temp) ans+=2;
                else if (abs(sum-2*temp)==1) ans++;
            }
        }
        return ans;
    }
};