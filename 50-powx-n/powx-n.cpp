class Solution {
public:
    double myPow(double x, int n) {
        return pow(x,n);
        
        double ans=1;
        for(int i=1; i<=n; i++){
           if(n<0) ans=1/(ans*x);
           else ans*=x;
        }
        return ans;
    }
};