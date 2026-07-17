class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = ranges::max(nums);
        vector<int> freq(mx + 1);
        for (int v : nums)
            ++freq[v];

        vector<long long> g(mx + 1);
        for (int d = mx; d > 0; --d) {
            long long m = 0;
            for (int k = d; k <= mx; k += d) {
                m += freq[k];
                g[d] -= g[k];
            }
            g[d] += m * (m - 1) / 2;
        }

        vector<long long> s(mx + 1);
        partial_sum(g.begin(), g.end(), s.begin());

        vector<int> ans(queries.size());
        ranges::transform(queries, ans.begin(), [&](long long q) {
            return int(ranges::upper_bound(s, q) - s.begin());
        });
        return ans;
    }
};