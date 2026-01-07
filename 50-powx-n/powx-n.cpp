class Solution {
    double binaryExp(double x, long n) {
        if(n==0) return 1;
        if(n%2==1) return x*binaryExp(x*x,n/2);
        return binaryExp(x*x, n/2);
    }
public:
    double myPow(double x, int n) {
        long N=n;
        if(N<0) return (1.0/binaryExp(x, -1*N));

        return binaryExp(x, (long) N);
    }
};