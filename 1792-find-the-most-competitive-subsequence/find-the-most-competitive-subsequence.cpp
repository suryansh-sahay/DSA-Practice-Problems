class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> q;
        int remains = nums.size() - k;
        for (int x : nums) {
            while (!q.empty() && q.back() > x && remains > 0) {
                remains--;
                q.pop_back();
            }
            q.push_back(x);
        }

        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(q[i]);
        }
        return ans;
    }
};