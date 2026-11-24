class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(), nums.end());
        int r=accumulate(nums.begin(), nums.end(), 0);

        while(l<r){
            int mid=l+(r-l)/2;

            int total=0, cnt=1;
            for(int num: nums){
                if(total+num>mid) total=num, cnt++;
                else total+=num;
            }
            if(cnt<=k) r=mid;
            else l=mid+1;
        }
        return l;
    }
};