class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLen = words[i].length();
            int j = i + 1;

            while (j < n && lineLen + 1 + words[j].length() <= maxWidth) {
                lineLen += 1 + words[j].length();
                j++;
            }

            int wordsCount = j - i;
            int totalChars = 0;
            for (int k = i; k < j; k++) {
                totalChars += words[k].length();
            }

            int totalSpaces = maxWidth - totalChars;
            string line;

            if (j == n || wordsCount == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line += string(maxWidth - line.length(), ' ');
            }
            else {
                int spacesPerGap = totalSpaces / (wordsCount - 1);
                int extraSpaces = totalSpaces % (wordsCount - 1);

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += string(spacesPerGap, ' ');
                        if (extraSpaces-- > 0) {
                            line += " ";
                        }
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};
