constexpr int P=1e9+7, N=2000;
using ll=long long;
static ll dp[N]; 
class Solution {
public:
    static int zigZagArrays(int n, int l, int r) {
        const int m=r-l+1;
        fill_n(dp, m, 1);
        for(int i=1; i<n; i++){
            bool dir=i&1;
            ll Sum=0;
            int i0=(-dir & m-1), iN=(-!dir &m-1), step=(dir)?-1:1;
            for( int j=i0; j!=iN+step; j+=step){
                ll x=dp[j];              
                dp[j]=Sum;              
                Sum=(Sum+x)%P;
            }
        }
        return 2*reduce(dp, dp+m, 0LL)%P;
    }
};