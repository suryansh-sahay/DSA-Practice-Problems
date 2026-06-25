class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max_cost=0;
        int ans=0;
        for(int i=0;i<costs.size();i++){
            max_cost=max(max_cost,costs[i]);
        }
        vector<int> cnt(max_cost+1,0);
        for(int i=0;i<costs.size();i++){
            cnt[costs[i]]++;
        }
        for(int i=0;i<max_cost+1;i++){
            if(cnt[i]==0) continue;
            if(coins<cnt[i]) break;
            long long total=cnt[i];
            long long num = min(total,(long long)coins/i);
            ans+=num;
            coins-=num*i;

        }
        return ans;
    }
};