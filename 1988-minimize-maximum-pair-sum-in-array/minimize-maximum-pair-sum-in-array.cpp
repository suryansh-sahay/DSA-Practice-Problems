class Solution {
private:

    vector<int> countSort(vector<int>& arr) {
        int n = arr.size();
        int maxval = 0;
        for (int i = 0; i < n; i++)
            maxval = max(maxval, arr[i]);

        vector<int> cntArr(maxval + 1, 0);

        for (int i = 0; i < n; i++)
            cntArr[arr[i]]++;

        for (int i = 1; i <= maxval; i++)
            cntArr[i] += cntArr[i - 1];

        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            ans[cntArr[arr[i]] - 1] = arr[i];
            cntArr[arr[i]]--;
        }

        return ans;
    }

public:
    int minPairSum(vector<int>& nums) {
        nums = countSort(nums);

        int mP = 0;
        int i = 0;
        while(i < nums.size() / 2) {
            mP = max(mP, nums[i] + nums[nums.size() - i - 1]);
            i ++;
        }

        return mP;
    }
};