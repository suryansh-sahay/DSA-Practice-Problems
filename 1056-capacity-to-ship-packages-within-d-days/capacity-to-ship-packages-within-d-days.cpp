class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(), weights.end());
        int r=0; 
        for(int num: weights) r+=num;
        
        while(l<r){
            int mid=l+(r-l)/2;
            int sum=0, count=1;

            for(int num: weights){
                if(sum+num > mid) count++, sum=0; 
                sum+=num;
            }
            if(count>days) l=mid+1;
            else r=mid; 
        }
        return l;
    }
};