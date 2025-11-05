class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;
        vector<vector<int>> buckets(n + 1);
        for (auto& p : freq)
            buckets[p.second].push_back(p.first);
        vector<int> res;
        for (int f = n; f >= 1 && (int)res.size() < k; --f) {
            for (int val : buckets[f]) {
                res.push_back(val);
                if ((int)res.size() == k)
                    break;
            }
        }
        return res;
    }
};
