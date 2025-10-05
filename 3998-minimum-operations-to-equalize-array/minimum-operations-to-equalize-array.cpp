class Solution {
public:
    int minOperations(vector<int>& nums) {
        for(int num: nums){
            if(num!=nums[0]) return 1;
        }
        return 0; 
    }
};