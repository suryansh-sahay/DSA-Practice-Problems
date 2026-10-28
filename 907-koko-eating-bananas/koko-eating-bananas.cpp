class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(), piles.end());

        while(l<r){
            int mid=l+(r-l)/2;

            int temp=0;
            for(int num: piles) temp+=1+((num-1)/mid);
            if(temp<=h) r=mid;
            else l=mid+1;
        }
        return r;
    }
};