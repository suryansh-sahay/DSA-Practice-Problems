class Solution {
public:
    int possibleStringCount(string word) {
        int sum=1,temp=1;
        for(int i=1; i<word.length(); i++){
            if(word[i]==word[i-1]) temp++;
            else sum+=(temp-1), temp=1;
        }
        return sum+temp-1;
    }
};