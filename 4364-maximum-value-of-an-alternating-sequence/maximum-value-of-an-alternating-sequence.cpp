class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long ans=s;
        long long k=n/2;
        if(k>0) ans=max(ans,1LL*s+k*m-(k-1));
        long long t=(n-1)/2;
        ans=max(ans,1LL*s+t*(m-1));
        return ans;
    }
};