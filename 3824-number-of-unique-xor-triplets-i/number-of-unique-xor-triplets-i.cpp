class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return n;

        int answer = 1;

        while (answer <= n)
            answer *= 2;

        return answer;
    }
};