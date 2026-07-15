class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int s=0, se=0;
        for(int i=1; i<=2*n; i+=2) s+=i;
        for(int i=2; i<=2*n; i+=2) se+=i;

        return gcd(s,se);
    }
};