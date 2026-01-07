#include <iostream>
#include <string>
using namespace std;

class Solution {
    int recurse(int i, int sign, string s, long long res){
        if(i>=s.size() || !isdigit(s[i])) return sign*res;
        res=res*10+(s[i]-'0');
        if(sign*res>INT_MAX) return INT_MAX;
        else if(sign*res<INT_MIN) return INT_MIN;
        return recurse(i+1, sign, s, res);
    }
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long res = 0; 

        while (i < s.size() && s[i] == ' ') i++;
        if (i == s.size()) return 0;

        if (s[i] == '-') { sign = -1; i++; }
        else if (s[i] == '+') i++;
        return recurse(i, sign, s, res);
    }
};