class Solution {
public:
vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    uint mask = 0;
    vector<uint> ps(1);
    for (char c : s)
        ps.push_back(mask ^= 1 << (c - 'a'));

    vector<bool> r;
    for (auto &q : queries) {
        uint odds = popcount(ps[q[1] + 1] ^ ps[q[0]]);
        r.push_back(q[2] >= odds / 2);
    }
    return r;
}
};