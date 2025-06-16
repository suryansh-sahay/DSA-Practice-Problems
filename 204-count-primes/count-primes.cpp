class Solution {
public:
    int countPrimes(int n) {

        vector<bool> isPrime(n,true);

        if(n<=2) return 0;
        isPrime[0]=false; isPrime[1]=false;

        for(int i=2; i*i<n; i++){
            if(isPrime[i]){
                for(int j=i*i; j<n; j+=i){
                    isPrime[j]=false;
                }
            }
        }   
        return count(isPrime.begin(), isPrime.end(), true);
    }
};