class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        unordered_map<uint64_t, int> freq;
        for (int i = 0, n = coordinates.size(); i < n; ++i) {
            uint32_t x = coordinates[i][0], y = coordinates[i][1];
            uint64_t key = ((uint64_t)x << 32) | y;
            ++freq[key];
        }
        long long res = 0;
        if (k) {
            for (auto &pos : freq) {
                uint32_t x = pos.first >> 32;
                uint32_t y = pos.first & 0xFFFFFFFF;
                int cnt = pos.second;
                for (int i = 0; i <= k; ++i) {
                    uint64_t key = ((uint64_t)(x ^ i) << 32) | (y ^ (k - i));
                    auto it = freq.find(key);
                    if (it != freq.end()) res += 1LL * cnt * it->second;
                }
            }
            return (int)(res / 2);
        }
        for (auto &pos : freq) {
            long long cnt = pos.second;
            res += cnt * (cnt - 1) / 2;
        }
        return (int)res;
    }
};