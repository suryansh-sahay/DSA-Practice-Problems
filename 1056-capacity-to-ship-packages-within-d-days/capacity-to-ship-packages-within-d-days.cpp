class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(), weights.end()), r=accumulate(weights.begin(), weights.end(), 0);

        while(l<r){
            int mid=l+(r-l)/2;
            int count=0, sum=0;
            for(int weight: weights){
                if(weight+sum > mid) count++, sum=0;
                sum+=weight;
            }
            count++;

            if(count<=days) r=mid;
            else l=mid+1;
        }
        return r;
    }
};