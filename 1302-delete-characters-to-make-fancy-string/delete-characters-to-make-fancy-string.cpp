class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3) return s;

        string ans;
        ans.reserve(s.length());  // avoid multiple reallocations
        ans += s[0];
        int count = 1;

        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1;
            }

            if (count < 3) {
                ans += s[i];
            }
        }

        return ans;
    }
};
