class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int mini=1;
        int maxi=piles[0];
        for(int i=0;i<n;i++){
            if(piles[i]>maxi)
            maxi=piles[i];
        }
        int res=0;

        while(mini<maxi){
            int mid=mini+(maxi-mini)/2;

            for(int i=0;i<n;i++){
                 res+=((piles[i]-1)/mid)+1;
            }
            
            if(res<=h){
                maxi=mid;
                res=0;
            }
            else if(res>h){
                mini=mid+1;
                res=0;
            }
            
        }
        return maxi;
    }
};