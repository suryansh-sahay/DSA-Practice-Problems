class Solution {
public:
int maxFrequency(vector<int>& nums, int k, int numOperations){
    int n = nums.size();
    unordered_map<int,int> freq;
    freq.reserve(n*2);
    for(int x: nums) freq[x]++;
    vector<long long> starts, ends;
    starts.reserve(n); ends.reserve(n);
    for(int x: nums){ starts.push_back((long long)x - k); ends.push_back((long long)x + k); }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    vector<pair<long long,int>> events; events.reserve(2*n);
    for(int i=0;i<n;i++){ events.emplace_back(starts[i], 1); events.emplace_back(ends[i] + 1, -1); }
    sort(events.begin(), events.end());
    int curr = 0, max_cover = 0;
    for(auto &e: events){ curr += e.second; max_cover = max(max_cover, curr); }
    int ans = min(max_cover, numOperations);
    for(auto &p: freq){
        int v = p.first;
        int existing = p.second;
        int starts_le = upper_bound(starts.begin(), starts.end(), v) - starts.begin();
        int ends_lt = lower_bound(ends.begin(), ends.end(), v) - ends.begin();
        int cover = starts_le - ends_lt;
        ans = max(ans, min(cover, existing + numOperations));
    }
    return ans;
}
};
