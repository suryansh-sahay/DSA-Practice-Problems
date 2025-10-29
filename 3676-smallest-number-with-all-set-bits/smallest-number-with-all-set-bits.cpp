class Solution {
public:
    int smallestNumber(int n) {
        int val=ceil(log2(n+1));
        return pow(2,val)-1;
    }
};