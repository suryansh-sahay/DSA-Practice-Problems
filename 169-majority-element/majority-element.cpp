class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int freq=0, value;
        for(int i=0; i<n; i++){
            if(freq==0) value=nums[i], freq=1;
            else if(nums[i]==value) freq++;
            else freq--;
        }
        return value;
    }
};