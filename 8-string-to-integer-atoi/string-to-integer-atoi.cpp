class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int i=0;
        while(i<n && s[i]==' ') i++;

        int sign=1;
        if(s[i]=='-') sign=-1, i++;
        else if(s[i]=='+') i++;

        long ans=0;
        while(i<n && isdigit(s[i])){
            ans=ans*10+(s[i]-'0'), i++;
            if(sign*ans>INT_MAX) return INT_MAX;
            if(sign*ans<INT_MIN) return INT_MIN;
        }
        return ans*sign;
    }
};