class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<vector<int>> edge(n);
        
        for(auto i : edges){
            int u = i[0], v = i[1];
            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        multiset<int> pos[n];
        multiset<int, greater<int>> neg[n];

        vector<long long> coins(n);

        auto dfs = [&](auto &dfs, int x, int p) -> void {
            if(cost[x] > 0){
                pos[x].insert(cost[x]);
            } else {
                neg[x].insert(cost[x]);
            }

            for(auto y : edge[x]){
                if(y == p) continue;
                dfs(dfs, y, x);

                for(auto i : pos[y]){
                    pos[x].insert(i);
                }
                for(auto i : neg[y]){
                    neg[x].insert(i);
                }

                while((int)pos[x].size() > 3) pos[x].erase(pos[x].begin());
                while((int)neg[x].size() > 3) neg[x].erase(neg[x].begin());
            }

            int ps = (int)pos[x].size(), ns = (int)neg[x].size();

            if(ps + ns < 3){
                coins[x] = 1;
            } else {
                long long mx = -9e18;

                if(ps >= 3){
                    auto itr = pos[x].rbegin();
                    int lst = *itr;
                    itr++;
                    int slst = *itr;
                    itr++;
                    int tlst = *itr;
                    mx = max(mx, 1LL * lst * slst * tlst);
                }

                if(ns >= 2 && ps >= 1){
                    auto itr = neg[x].rbegin();
                    int lst = *itr;
                    itr++;
                    int slst = *itr;
                    int tlst = *pos[x].rbegin();
                    mx = max(mx, 1LL * lst * slst * tlst);
                }

                if(mx > 0){
                    coins[x] = mx;
                }
            }
        };

        dfs(dfs, 0, -1);

        return coins;
    }
};