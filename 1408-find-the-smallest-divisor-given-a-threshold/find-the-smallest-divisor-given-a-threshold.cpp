class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(), nums.end());

        while(l<r){
            int mid=l+(r-l)/2;
            long long sum=0; 
            for(int num: nums) {
                sum+=(num-1)/mid+1;  
                if(sum>threshold) break;
            }

            if(sum>threshold)  l=mid+1; 
            else r=mid;   
        } 
        return l;
    }
};