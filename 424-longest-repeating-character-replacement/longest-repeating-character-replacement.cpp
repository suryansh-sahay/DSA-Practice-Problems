class Solution {
public:
    int characterReplacement(string s, int kkk) {
        int ans=0;
        for(int k=0; k<26; k++){
            int maxi=0, j=0, kk=kkk;
            for(int i=0; i<s.length(); i++){
                if(s[i]!='A'+k) kk--;
                while(kk<0){
                    if(s[j]!='A'+k) kk++;
                    j++;
                }
                maxi=max(maxi, i-j+1);
            }
            ans=max(ans, maxi);
        }
        return ans;
    }
};