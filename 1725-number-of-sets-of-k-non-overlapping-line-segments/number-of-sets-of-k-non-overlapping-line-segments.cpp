const int mod=1e9+7,MX=2e3+10;
int mult(int a,int b){return (1ll*a*b)%mod;}
int fact[MX],inv[MX],invfact[MX];
void init_INV(){
	fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
    for (int i = 2; i < MX; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
}
int ncr(int n,int r){
	if(r > n) return 0;
	return (1LL * fact[n] * invfact[n-r] % mod) * 1LL *invfact[r] % mod;
}

class Solution {
public:
    int numberOfSets(int n, int k) {
        init_INV();
        return ncr(n + k - 1, 2 * k);
    }
};