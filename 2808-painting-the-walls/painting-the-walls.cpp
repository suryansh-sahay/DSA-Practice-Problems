class Solution {
    int solve(vector<int> &c, vector<int> &t, int &n, int i, int x, unordered_map<int,int> *mp) {
        if(x>=n-i) {
            return 0;
        }
        if(i==n) {
            if(x<0) {
                return 1e9;
            }
            return 0;
        }
        if(mp[i].count(x)) {
            return mp[i][x];
        }
        int f = solve(c,t,n,i+1,x-1,mp);
        int p = c[i] + solve(c,t,n,i+1,x+t[i],mp);
        return mp[i][x] = min(f,p);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        unordered_map<int,int> dp[n];
        return solve(cost,time,n,0,0,dp);
    }
};

