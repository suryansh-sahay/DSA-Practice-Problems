class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int even = 1, odd = 0;
        int pairity = 0, ans = 0;

        for(int num : arr){

            pairity = (pairity + num) % 2;
            if(pairity == 1) ans = (ans + even) % MOD;
            else ans = (ans + odd) % MOD;

            if(pairity == 1) odd++;
            else even++;
        }
        return ans;       
        
    }
};