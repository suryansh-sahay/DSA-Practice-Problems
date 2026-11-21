class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mp1(256, 0);
        vector<int> mp2(256, 0);

        for(int i=0; i<s.length(); i++){
            if(mp1[s[i]]!=mp2[t[i]]) return false;
            mp1[s[i]]=i+1;
            mp2[t[i]]=i+1;
        }
        return true;
    }
};