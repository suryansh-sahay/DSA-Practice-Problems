class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char, int> mp;

        int j=0, maxi=0;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
            while(mp[s[i]]>1) mp[s[j]]--, j++;
            maxi=max(maxi, i-j+1);
        }
        return maxi;
    }
};