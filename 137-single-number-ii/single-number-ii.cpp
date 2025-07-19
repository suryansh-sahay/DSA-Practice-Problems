class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int first=0, second=0; 
        
        for(int num: nums){
            first=(first^num) & ~second;
            second=(second^num) & ~first;
        }
        return first;
    }
};