class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int sum=0, ans=0;
        for(int num: nums){
            sum+=num;
            if(sum==k) ans++;
            if(mp.find(sum-k)!=mp.end()) ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;                                   
    }
};

