class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;
        int count = 0;

        for (int i=0;i<nums.size();i++) {
            if (nums[i] == pivot) {
                count++;
            }
            if (nums[i] < pivot) {
                result.push_back(nums[i]);
            }
        }

        for (int i = 0; i < count; i++) {
            result.push_back(pivot);
        }

        for (int i=0;i<nums.size();i++) {
            if (nums[i] > pivot) {
                result.push_back(nums[i]);
            }
        }

        return result;
    }
};