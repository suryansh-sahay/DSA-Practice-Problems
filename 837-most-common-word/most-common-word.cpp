class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {

        map<string, int> allowedWords;
        map<string, bool> bannedWords;

        for (int i = 0; i < banned.size(); i++) {
            bannedWords[banned[i]] = 1;
        }
        int i = 0, n = paragraph.size();
        while (i < n) {
            while (i < n && !((paragraph[i] >= 'a' && paragraph[i] <= 'z') ||
                              (paragraph[i] >= 'A' && paragraph[i] <= 'Z')))
                i++;

            string temp = "";
            while (i < n && ((paragraph[i] >= 'a' && paragraph[i] <= 'z') ||
                             (paragraph[i] >= 'A' && paragraph[i] <= 'Z'))) {
                char ch = tolower(paragraph[i]);
                temp += ch;
                i++;
            }
            if (!bannedWords.contains(temp) && temp != "") {
                allowedWords[temp]++;
            }
        }
        int maxFreq = INT_MIN;
        string ans = "";
        for (auto& it : allowedWords) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};