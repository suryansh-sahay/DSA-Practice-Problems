class Solution {
public:
    int minimax(int i, int j, int value, int player, vector<int>& piles,map<vector<int>, int>& mp) {
        if (j > i)
            return value;
        if (mp.find({i, j, player}) != mp.end())
            return mp[{i, j, player}];
        vector<vector<int>> v = {{i, i + 1, j}, {j, i, j - 1}};
        if (player) {
            for (auto& a : v) {
                value = max(value + a[0],minimax(a[1], a[2], value, 1 - player, piles,mp));
            }
            mp[{i,j,player}] = value;
            return value;
        }
        for (auto& a : v) {
            value = max(value - a[0],minimax(a[1], a[2], value, 1 - player, piles,mp));
        }
        mp[{i,j,player}] = value;
        return value;
    }
    bool stoneGame(vector<int>& piles) { 
        map<vector<int>, int> mp;
        int value = minimax(0,piles.size()-1,0,1,piles,mp);
        if(value>0) return false;
        return true;

    }
};