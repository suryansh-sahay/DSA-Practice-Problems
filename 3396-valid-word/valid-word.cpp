class Solution {
private:
    bool checkVowel(char c) {
        c = tolower(c);
        return  (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

public:
    bool isValid(string word) {
        if(word.length()<3) return false;
        int vcount = 0, ccount = 0;
        for (char ch : word) {
            if (!isdigit(ch) && !isalpha(ch))
                return false;
            if (isalpha(ch)){
                if (checkVowel(ch))
                    vcount++;
                else
                    ccount++;
            }
        }
        return vcount>=1 && ccount>=1;
    }
};