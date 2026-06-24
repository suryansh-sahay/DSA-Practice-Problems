class Solution {
public:
    const int mod = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;
        if (n == 1) return k;
        if (k == 1) return 0;

        vector<long long> vec(k, 0);
        iota(vec.begin(), vec.end(), 0);

        vector<vector<long long>> mat(k, vector<long long>(k, 0));
        for (int i = 0; i < k; ++i) {
            int down = k - 1 - i;
            for (int j = down + 1; j < k; ++j) {
                mat[i][j] = 1;
            }
        }

        auto trans = mulPow(mat, n - 2);
        auto out = vecMul(trans, vec);

        long long ans = 0;
        for (long long val : out) {
            ans = (ans + val) % mod;
        }
        return ans * 2 % mod;
    }

    vector<vector<long long>> mulPow(vector<vector<long long>>& a, int exp) {
        int n = a.size();
        vector<vector<long long>> res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            res[i][i] = 1;
        }
        while (exp) {
            if (exp % 2 == 1) {
                res = matMul(res, a);
            }
            a = matMul(a, a);
            exp /= 2;
        }
        return res;
    }

    vector<vector<long long>> matMul(vector<vector<long long>>& a, 
                                        vector<vector<long long>>& b) {
        int n = a.size();
        vector<vector<long long>> res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
                }
            }
        }
        return res;
    }

    vector<long long> vecMul(vector<vector<long long>>& a, 
                                        vector<long long>& b) {
        int n = a.size();
        vector<long long> res(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i] = (res[i] + a[i][j] * b[j]) % mod;
            }
        }
        return res;

    }
};