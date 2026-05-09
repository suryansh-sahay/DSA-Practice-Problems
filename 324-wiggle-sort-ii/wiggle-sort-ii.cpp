class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> hold = nums;
        sort(hold.begin(), hold.end());

        int mid = (n - 1) / 2;
        int end = n - 1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = hold[mid--];
            } else {
                nums[i] = hold[end--];
            }
        }
    }
};