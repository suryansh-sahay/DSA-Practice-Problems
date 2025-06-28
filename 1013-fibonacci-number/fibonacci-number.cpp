// class Solution {
//     private:
//     int fibo(int n){
//         if(n==0) return 0;
//         if(n==1) return 1;
//         return fibo(n-1)+fibo(n-2);
//     }
// public:
//     int fib(int n) {
//         return fibo(n);
//     }
// };


class Solution {
public:
    int fib(int n) {
        double sqrt5 = sqrt(5);
        double fibN = pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n);
        return round(fibN / sqrt5);
    }
};