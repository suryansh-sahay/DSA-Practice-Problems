class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int maxLen = 0, start = 0;

        for(int end = 0; end < s.length(); end++) {
            if(mp.find(s[end]) != mp.end() && mp[s[end]] >= start){
                start = mp[s[end]] + 1;
            }
            mp[s[end]] = end; 
            maxLen = max(maxLen, end - start + 1); 
        }
        return maxLen;
    }
};