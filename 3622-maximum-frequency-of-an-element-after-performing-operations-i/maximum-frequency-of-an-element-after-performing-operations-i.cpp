class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        int freq[maxNum + 1], accumu[maxNum + 1];
        memset(freq, 0, sizeof(freq));
        memset(accumu, 0, sizeof(accumu));
        for (const int num: nums) {
            ++freq[num];
        }
        for (int i = minNum; i <= maxNum; i++) {
            accumu[i] = accumu[i - 1] + freq[i];
        }
        int res = 0;
        for (int i = minNum; i <= maxNum; i++) {
            // (l, r]
            int l = max(0, i - k - 1), r = min(maxNum, i + k);
            int totalCnt = accumu[r] - accumu[l];
            int opCnt = totalCnt - freq[i];
            res = max(res, freq[i] + min(opCnt, numOperations));
        }
        return res;
    }
};