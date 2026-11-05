class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int count=0;
        unordered_map<int,int>mp;

        for (int i=0;i<arr.size();i++) {
            int rem=((arr[i]%k)+k)%k;
            int need=(k-rem)%k;

            if (mp.find(need)!=mp.end()&&mp[need]>0){
                count++;
                mp[need]--;
            } else mp[rem]++;
        }

        return count >= arr.size() / 2;
    }
};