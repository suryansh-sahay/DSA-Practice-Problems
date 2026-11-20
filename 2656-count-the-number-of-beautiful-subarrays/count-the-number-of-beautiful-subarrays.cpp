class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
       unordered_map<int, int> mp;
       mp[0]=1;
       int sum=0; long long ans=0;
       for(int num:  nums){
          sum^=num;
          if(mp.find(sum)!=mp.end()) ans=ans+mp[sum];
          mp[sum]++;
       } 
       return ans;
    }
};