class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(), piles.end());

        while(l<r){
            int mid=l+(r-l)/2;
            
            int hours=0;
            for(int pile: piles) hours+=1+(pile-1)/mid;

            if(hours<=h) r=mid;
            else l=mid+1;
        }
        return l;
    }
};