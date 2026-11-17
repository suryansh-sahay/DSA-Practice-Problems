class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        ms(nums, 0, nums.size()-1);
        return nums;
    }
    void ms(vector<int>& nums, int l, int r){
        if(l>=r) return;
        int mid=l+(r-l)/2;
        ms(nums, l, mid);
        ms(nums, mid+1, r);
        merge(nums, l, mid, r);
    }
    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;

        int l=low, r=mid+1;
        while(l<=mid && r<=high){
            if(nums[l]<=nums[r]) temp.push_back(nums[l]), l++;
            else temp.push_back(nums[r]), r++;
        }
        while(l<=mid) temp.push_back(nums[l]), l++;
        while(r<=high) temp.push_back(nums[r]), r++;

        for(int i=low; i<=high; i++) nums[i]=temp[i-low];
    }
};