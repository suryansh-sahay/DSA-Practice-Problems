class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {     
        int maxi=-1;
        for(int num: piles) if(num > maxi) maxi=num;
        
        int l=1, r=maxi;
        while(l<=r){
            int mid=l+(r-l)/2;
            long long sum=0;
            for(int num: piles){
                sum+=ceil((num+mid-1)/mid);
            }
            if(sum>h) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};