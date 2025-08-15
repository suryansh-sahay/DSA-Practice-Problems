class Solution {
public:
    bool isPowerOfFour(int n) {
        // return n>0 && ((log(n)/log(4))==floor(log(n)/log(4)));
        return n>0 && ((n&(n-1))==0) && ((n& 0x55555555) !=0);
    }
};