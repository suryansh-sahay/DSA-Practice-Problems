class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> f;

        for(int num: nums) f[num]++;

        int maxi=0;
        for(auto &num: f){
            long long curr=num.first;

            int temp=0;
            if(curr==1){
                maxi=max(maxi,(f[curr]%2==0?f[curr]-1:f[curr]));
                continue;
            }
            while(f.count(curr) && f[curr]>=2){
                temp+=2;
                curr*=curr;
            }
            if(f.count(curr) && f[curr]==1) temp++;
            else temp--;
            maxi=max(maxi, temp);
        }
        return maxi;
    }
};