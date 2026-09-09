class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int count = 0;

        while (n) {
           if(n%2) count++;
           n/=2;
        }
        return count;
    }
};

// 1 0 1 0 
// 0 1 0 1 
// 1 1 1 1 = 15
// 1 1 1 0 = 1 1 1 0
//           1 1 0 1 = 1 1 0 0 
//                     1 0 1 1 = 1 0 0 0 
//                               0 1 1 1 = 0 0 0 0