class Solution {
public:
    long long maximumValue(int n, int s, int m) {        
        if(n==1) return s;
        long long k=1LL*(n/2);
        return 1LL*s+(k)*m-(k-1);
    }
};