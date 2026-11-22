class Solution {
public:
    int characterReplacement(string s, int kkk) {
        unordered_set<char> mp;
        for(char c: s) mp.insert(c);
        int ans=0;
        for(int k=0; k<26; k++){
            char ch='A'+k;
            if(mp.find(ch)==mp.end()) continue;
            int maxi=0, j=0, kk=kkk;
            for(int i=0; i<s.length(); i++){
                if(s[i]!=ch) kk--;
                while(kk<0){
                    if(s[j]!=ch) kk++;
                    j++;
                }
                maxi=max(maxi, i-j+1);
            }
            ans=max(ans, maxi);
        }
        return ans;
    }
};