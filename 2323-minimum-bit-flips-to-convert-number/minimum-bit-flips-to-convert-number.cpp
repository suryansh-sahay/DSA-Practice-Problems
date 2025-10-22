class Solution {
public:
    int minBitFlips(int start, int goal) {
    int xorr=start^goal; 
    int ans=0;
    while(xorr>0){
        ans+=xorr&1;
        xorr>>=1;
    }
    return ans;
    }
};