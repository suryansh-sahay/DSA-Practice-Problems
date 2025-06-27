class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0, r = n - 1;
        while (l < r) {
            if (!isalnum(s[l]) && !isalnum(s[r]))
                l++, r--;
            else if (!isalnum(s[l]))
                l++;
            else if (!isalnum(s[r]))
                r--;
            else {
                if (tolower(s[l]) != tolower(s[r]))
                    return false;
                else {
                    l++, r--;
                }
            }
        }

        return true;
    }
};