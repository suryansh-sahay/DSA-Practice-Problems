class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        map<char,int>m;
        int ans=0;
        int l=0,r=0;
        while(r<n){
            m[s[r]]++;
            while(l<n && m[s[r]]>1){
                m[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};