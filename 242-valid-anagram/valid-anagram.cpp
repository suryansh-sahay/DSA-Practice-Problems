class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> value1, value2;
        for(char c: s){
            value1[c]++;
        }
        for(char c: t) value2[c]++;
        return value1==value2;
    }
};