#include <vector>
#include <map>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (int n : nums)
            freq[n]++;

        // Min-heap of (frequency, number)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto& [num, count] : freq) {
            pq.push({count, num});
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
