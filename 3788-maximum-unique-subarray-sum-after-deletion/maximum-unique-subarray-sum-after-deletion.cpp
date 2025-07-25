class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s;
        for(int num : nums) s.insert(num);
        int result = 0;
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (*it > 0) result += *it;
        }
        if (result == 0) result = *s.rbegin();
        return result;
    }
};