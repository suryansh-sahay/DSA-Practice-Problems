class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, r=nums.size()-1;

        while(l<r){
            int mid=l+(r-l)/2;
            if(mid%2==0) mid--;
            if(mid==0 || nums[mid]!=nums[mid-1]) r=mid-1;
            else l=mid+1;
        }
        return nums[l];
    }
};