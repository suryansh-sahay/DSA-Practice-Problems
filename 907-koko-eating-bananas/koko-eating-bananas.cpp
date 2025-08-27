class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {     
        int maxi=1;
        long long total=0;
        for(int num: piles){
           total+=num;
           if(num>maxi) maxi=num;
        }
        int l=max(1LL, (total-1)/h+1);
        
        int r=maxi;
        while(l<=r){
            int mid=l+(r-l)/2;
            long long sum=0;
            for(int num: piles){
                sum+=(num+mid-1)/mid;
            }
            if(sum>h) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};