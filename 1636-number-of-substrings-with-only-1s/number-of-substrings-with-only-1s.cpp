class Solution {
public:
   
    const int MOD=1e9+7;
    int numSub(string s) {
        long long ans=0, temp=0;
        for(char c: s){
            if(c=='0') ans=(ans+temp*(temp+1)/2)%MOD, temp=0;
            else temp++; 
        }
        return (ans+temp*(temp+1)/2)%MOD;
    }
};