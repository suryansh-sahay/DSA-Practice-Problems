class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if( n == 1) return 1;
        int minIndex=0;
        int maxIndex=0;

         for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }

            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        int st = min(maxIndex,minIndex);
        int end = max(maxIndex,minIndex);

        int one = end + 1;
        int two = n - st;
        int three = (st + 1) + (n - end);

        int ans = min({one, two , three});
        return ans;

    }   
};