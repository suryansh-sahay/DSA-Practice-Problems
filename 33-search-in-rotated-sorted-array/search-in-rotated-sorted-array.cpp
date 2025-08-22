class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();

        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] == target) return mid;

            if (arr[mid] <= arr[r]) {
                if (target > arr[mid] && target <= arr[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            } else {
                if (target >= arr[l] && target < arr[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};