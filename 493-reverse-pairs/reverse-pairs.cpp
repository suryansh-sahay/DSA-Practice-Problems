class Solution {
public:
    int reversePairs(vector<int> nums) {
        int n=nums.size()-1;
        int ans=0;
        ms(nums, 0, n, ans);  
        return ans;    
    }
    void ms(vector<int>&nums, int l, int h, int &ans){
        if(l>=h) return;
        int mid=l+(h-l)/2;
        ms(nums, l, mid, ans);
        ms(nums, mid+1, h, ans);
        merge(nums, l, h, ans);
    }
    void merge(vector<int>& nums, int low, int high, int &ans){
        int mid=low+(high-low)/2;
        int l=low, r=mid+1;

        while(l<=mid && r<=high){
            if(nums[l] <= (long long)2*nums[r]) l++;
            else ans+=(mid-l+1), r++;
        }       

        vector<int> temp;
        l=low, r=mid+1;
        while(l<=mid && r<=high){
            if(nums[l]<=nums[r]) temp.push_back(nums[l++]);
            else temp.push_back(nums[r++]);
        }

        while(l<=mid) temp.push_back(nums[l++]);
        while(r<=high) temp.push_back(nums[r++]);

        for(int i=low; i<=high; i++) nums[i]=temp[i-low];
    }
};