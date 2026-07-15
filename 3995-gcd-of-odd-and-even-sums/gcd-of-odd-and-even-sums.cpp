class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int a=n*n, b=n*(n+1);
        
        while(b!=0){
            int r=a%b;
            a=b;
            b=r;
        }
        return a;
    }
};