class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length(), n=t.length();

        string ans="";
        if(m<n) return ans;

        unordered_map<char, int> mp;
        for(char c: t) mp[c]++;

        int r=0, l=0, cnt=0;;
        int start=-1, minl=INT_MAX;
        while(r<m){
            if(mp[s[r]]>0) cnt++;
            mp[s[r]]--;
            while(cnt==n && l<m){
                if(r-l+1<minl) start=l, minl=r-l+1;
                if(mp[s[l]]>=0) cnt--;
                mp[s[l++]]++;

            }
            r++;
        }
        return (start==-1?"":s.substr(start, minl));
    }
};