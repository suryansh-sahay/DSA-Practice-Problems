class Solution {
public:
    int dp[505][505];
    int f(vector<int>&cost,vector<int>&time,int i,int p){
        if(p<=0) return 0;
        if(i==time.size()) return 1e9;
        if(dp[i][p]!=-1) return dp[i][p];
        int ans = 1e9;
        ans = min(ans,cost[i]+f(cost,time,i+1,p-time[i]-1));
        ans = min(ans,f(cost,time,i+1,p));
        return dp[i][p] = ans;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp,-1,sizeof(dp));
        return f(cost,time,0,time.size());
    }
};