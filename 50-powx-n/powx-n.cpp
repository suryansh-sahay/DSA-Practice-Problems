class Solution {
public:
    double square(double x, long long n){
        if(n==0) return 1;
        if(n%2==0) return square(x*x, n/2);
        else return x*square(x, n-1);
    }

    double myPow(double x, int n) {
       long long N=n;
       if(n<0) x=1/x, N=N*(-1);
       return square(x, N);
    }
};