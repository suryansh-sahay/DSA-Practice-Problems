class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26);

        int fr=0, j=0, ans=0;
        for(int i=0; i<s.length(); i++){
            freq[s[i]-'A']++;

            fr=max(fr, freq[s[i]-'A']);

            while(i-j+1-fr>k){
                freq[s[j]-'A']--;
                j++;
            }
            ans=max(ans, i-j+1);
        }
        return ans;
    }
};