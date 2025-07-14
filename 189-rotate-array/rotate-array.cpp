class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin() + k);
        // reverse(nums.begin() + k, nums.end());

        // int j = 0;
        // int temp = nums[j];
        // for (int i = 0; i < n; i++) {
        //     j = (j + k) % n;
        //     int temp1 = nums[j];
        //     nums[j] = temp;
        //     temp = temp1;
        // }
            
        int count = 0;  // Number of elements moved

        for (int start = 0; count < n; start++) {
            int current = start;
            int prev = nums[start];

            do {
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);  // Finish one cycle
        }
    }
};