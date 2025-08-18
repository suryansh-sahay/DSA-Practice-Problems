class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0, r=n-1;
        int left=-1, right=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target && (mid==0 || nums[mid-1]<target)) {
              left=mid; break;
            } else if(nums[mid]<target) l=mid+1;
            else r=mid-1;
        }
        l=0, r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target && (mid==n-1 || nums[mid+1]>target)){
                right=mid; break;
            } else if(nums[mid]>target) r=mid-1;
            else l=mid+1; 
        }
        return {left, right};
    }
};