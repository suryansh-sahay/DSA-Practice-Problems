class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> arrl(26, -1);
        vector<int> arru(26, -1);

        for(int i=0; i<word.size(); i++){
            char ch=word[i];
            if(islower(ch)) arrl[ch-'a']=i;
            else {
                if(arru[ch-'A']==-1) arru[ch-'A']=i;
            }
        }
        int count=0;

        for(int i=0; i<26; i++){
            if(arrl[i]!=-1 && arru[i]!=-1 && arru[i]>arrl[i]) count++;
        }
        return count;
    }
}; 