class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0;
        int n=nums.size();
        
        for(int num: nums) x^=num;

        if(x!=0) return n;
        
        for(int val: nums){
            if(val!=0) return n-1;
        }

        return 0;
    }
};