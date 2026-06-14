class Solution {
public:
int maxPointsInsideSquare(vector<vector<int>>& ps, const string &s) {
    int second_min_sz = INT_MAX;
    vector<int> min_sz(26, INT_MAX);
    for (int i = 0; i < ps.size(); ++i) {
        int sz = max(abs(ps[i][0]), abs(ps[i][1]));
        if (min_sz[s[i] - 'a'] > sz)
            swap(min_sz[s[i] - 'a'], sz);
        second_min_sz = min(second_min_sz, sz);
    }
    return ranges::count_if(min_sz, [&](int sz){ return sz < second_min_sz; });
}
};