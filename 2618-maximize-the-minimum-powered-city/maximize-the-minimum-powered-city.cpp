#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, long long k) {
        long long low = 0;
        long long high = k + accumulate(stations.begin(), stations.end(), 0LL);

        while (low < high) {
            long long mid = high + (low - high) / 2;
            if (check(stations, mid, r, k)) low = mid;
            else high = mid - 1;
        }
        return low;
    }

private:
    bool check(const vector<int>& stations, long long mid, int r, long long k) {
        int n = stations.size();
        vector<long long> diff(n + 1, 0);
        long long sum = 0;

        for (int i = 0; i <= min(n - 1, r); ++i) sum += stations[i];

        long long extra = 0;
        for (int i = 0; i < n; ++i) {
            extra += diff[i];
            long long effective = sum + extra;

            if (effective < mid) {
                long long need = mid - effective;
                if (need > k) return false;
                k -= need;
                extra += need;
                int end = min(n, i + 2 * r + 1);
                diff[end] -= need;
            }

            int addPos = i + r + 1;
            if (addPos < n) sum += stations[addPos];
            int removePos = i - r;
            if (removePos >= 0) sum -= stations[removePos];
        }

        return true;
    }
};
