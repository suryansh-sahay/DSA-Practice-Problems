class Solution {
private:
    bool isPali(const string& s, int l, int r) {
        if (l >= r)
            return true;
        if (!isalnum(s[l]))
            return isPali(s, l+1, r);
        else if (!isalnum(s[r]))
           return  isPali(s, l, r-1);
        else if (tolower(s[l]) != tolower(s[r]))
            return false;
        else {
           return isPali(s, l+1, r-1);
        }
    }

public:
    bool isPalindrome(string s) { return isPali(s, 0, s.size()-1); }
};