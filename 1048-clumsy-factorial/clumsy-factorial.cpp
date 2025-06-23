class Solution {
private:
    int clum(int n) {
       if(n<=2) return n;
       if(n<=4) return n+3;
       if(n%4==0) return n+1;
       else if(n%4<=2) return n+2;
       else{return n-1;}

        return n*(n - 1) / (n - 2) + (n - 3) - clum(n-4);
    }

public:
    int clumsy(int n) {
        return clum(n);
    }
};