class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long total_nums = n * n;

        long long sum_all = 0, sum_sq_all = 0;
        for (auto &row : grid) {
            for (int x : row) {
                sum_all += x;
                sum_sq_all += (long long)x * x;
            }
        }

        long long sum_expected = total_nums * (total_nums + 1) / 2;
        long long sum_sq_expected = total_nums * (total_nums + 1) * (2 * total_nums + 1) / 6;

        long long diff = sum_all - sum_expected; // a - b
        long long sum_ab = (sum_sq_all - sum_sq_expected) / diff; // a + b

        long long a = (diff + sum_ab) / 2;
        long long b = a - diff;

        return {(int)a, (int)b};
    }
};
