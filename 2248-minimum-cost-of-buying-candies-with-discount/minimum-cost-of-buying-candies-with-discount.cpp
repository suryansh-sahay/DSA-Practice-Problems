class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(), cost.end(), greater<int>());
        int ans=0;
        for(int i=0; i<n; i=i+3){
           if(i<n-1) ans+=cost[i]+cost[i+1];
        }
        if(n%3==1) ans+=cost[n-1];
        return ans;
    }
};