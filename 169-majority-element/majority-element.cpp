class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me=nums[0], frq=1;
        for(int i=1; i<nums.size(); i++){
            if(!frq) me=nums[i], frq=1;
            else if(nums[i]==me) frq++;
            else frq--;
        }
        return me;
    }
};