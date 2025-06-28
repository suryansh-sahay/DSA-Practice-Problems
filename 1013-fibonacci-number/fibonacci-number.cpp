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


class Solution{
    public:
    int fib(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        int ans=1, temp1, temp2=0;
        for(int i=2; i<=n; i++){  
            temp1=ans; 
            ans=temp1+temp2; 
            temp2=temp1;
        }
        return ans;

    }
};