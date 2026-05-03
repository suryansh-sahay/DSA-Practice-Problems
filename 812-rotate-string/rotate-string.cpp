

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        string word = s + s;

        for (int i = 0; i < s.length(); i++) {
            if (word.substr(i, s.length())==goal) {
                return true;
            }
        }
        return false;
    }
};