class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char, int> mp;

        int j=0, maxi=0;
        for(int i=0; i<n; i++){
            if(mp.find(s[i])!=mp.end() && mp[s[i]]>=j) j=mp[s[i]]+1; 
            maxi=max(maxi, i-j+1);
            mp[s[i]]=i;
        }
        return maxi;
    }
};