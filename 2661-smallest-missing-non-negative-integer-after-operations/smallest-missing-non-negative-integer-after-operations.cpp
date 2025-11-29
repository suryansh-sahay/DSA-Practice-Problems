class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> remainderCount(value, 0);

        for (int num : nums) {
            int rem = ((num % value) + value) % value;
            remainderCount[rem]++;
        }

        int result = 0;
        while (remainderCount[result % value] > 0) {
            remainderCount[result % value]--;
            result++;
        }

        return result;
    }
};