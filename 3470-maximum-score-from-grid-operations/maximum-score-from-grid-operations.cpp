class Solution {
public:
    long long maximumScore(vector<vector<int>>& g) {
        int n = g.size();
        vector p(n, vector<long long>(n + 1, 0));
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < n; ++i)
                p[j][i + 1] = p[j][i] + g[i][j];

        vector<long long> f(n + 1), d(n + 1);
        for (int j = 1; j < n; ++j) {
            vector<long long> nf(n + 1), nd(n + 1);
            long long b = -2e18;
            for (int h = 0; h <= n; ++h)
                b = max(b, f[h] - p[j - 1][h]), nf[h] = b + p[j - 1][h];
            b = -2e18;
            for (int h = 0; h <= n; ++h)
                b = max(b, d[h]), nf[h] = max(nf[h], b);
            b = -2e18;
            for (int h = n; h >= 0; --h)
                nd[h] = b - p[j][h], b = max(b, max(f[h], d[h]) + p[j][h]);
            f = nf, d = nd;
        }
        long long a = 0;
        for (int i = 0; i <= n; ++i)
            a = max({a, f[i], d[i]});
        return a;
    }
};