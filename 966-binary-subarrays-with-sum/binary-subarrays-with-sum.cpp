class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0, ans=0; 
        unordered_map<int, int> mp;
        mp[0]=1;

        for(int num: nums){
            sum+=num;
            if(mp.count(sum-goal)) ans+=mp[sum-goal];
            mp[sum]++;
        }
        return ans;
    }
};

