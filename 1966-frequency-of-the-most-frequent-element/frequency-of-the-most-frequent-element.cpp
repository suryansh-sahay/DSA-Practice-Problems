class Solution {
public:
    int maxFrequency(vector<int>& nums, long k) {
        sort(nums.begin(), nums.end());
        
        long curr = 0, n=nums.size();
        int j=0;
        for (int i = 0; i < n; i++) {
            curr += nums[i];
            if (k < ((long)nums[i] * (i - j + 1) - curr)) curr-=nums[j++];
        }
        return n-j;
    }
};