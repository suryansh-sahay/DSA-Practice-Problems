class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int ans=0;
        for(int i=0; i<cost.size(); i=i+3){
           if(i<cost.size()-1) ans+=cost[i]+cost[i+1];
           if(i==cost.size()-1) ans+=cost[i];
        }
        return ans;
    }
};