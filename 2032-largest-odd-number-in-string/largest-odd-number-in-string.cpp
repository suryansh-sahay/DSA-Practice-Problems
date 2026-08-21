class Solution {
public:
    string largestOddNumber(string num) {
        int t=-1;
        for(int i=num.length()-1; i>=0; i--){
            if((num[i]-'0')%2==1){t=i; break;}
        }
        return num.substr(0,t+1);
    }
};