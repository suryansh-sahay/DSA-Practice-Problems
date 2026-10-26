class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return x;
        int l=0, r=x/2;

        while(l<=r){
            int mid=l+(r-l)/2;
            if((long long)mid*mid==x) return mid;
            if((long long)mid*mid<x) l=mid+1;
            else r=mid-1;
        } 
        return r;    
    }
};