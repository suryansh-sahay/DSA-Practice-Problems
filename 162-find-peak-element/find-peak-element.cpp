class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0, r=nums.size()-1;

        while(l<r){
            int mid=l+(r-l)/2;

           if(nums[mid]<=nums[r]) l=mid+1;
           else if(nums[mid]<=nums[l]) r=mid-1;
           else {
              if(nums[mid-1]>nums[mid]) r=mid-1;
              else if (nums[mid+1]>nums[mid]) l=mid+1;
              else return mid; 
           }
        }
        return l;
    }
};