class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(), nums.end());
        int r=accumulate(nums.begin(), nums.end(), 0);

        while(l<=r){
            int mid=l+(r-l)/2;
            int sum=0, count=1;
            
            for(int num: nums){
                if(sum+num>mid) count++, sum=0;
                sum+=num;
            }
            if(count>k) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};