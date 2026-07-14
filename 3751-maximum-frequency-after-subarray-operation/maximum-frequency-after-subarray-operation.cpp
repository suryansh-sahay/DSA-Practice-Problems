class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int cnt[51] = {}, res = 0, cnt_k = 0;
        for (int n : nums) {
            cnt[n] = max(cnt[n], cnt_k) + 1;
            res += n == k;
            cnt_k += n == k;
            res = max(res, cnt[n]);
        }
        return res;
    }
};