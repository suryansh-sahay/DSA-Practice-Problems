class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        ms(nums, 0, nums.size()-1);
        return nums;
    }
    void ms(vector<int>& arr, int l, int h){
        if(l>=h) return;

        int mid=l+(h-l)/2;
        ms(arr, l, mid);
        ms(arr, mid+1, h);
        merge(arr, l, mid, h);
    }

    void merge(vector<int>& arr, int low, int mid, int high){
        vector<int> temp;
        int l=low, r=mid+1;
        while(l<=mid && r<=high){
            if(arr[l]<=arr[r]) temp.push_back(arr[l++]);
            else temp.push_back(arr[r++]);
        }
        while(l<=mid) temp.push_back(arr[l++]);
        while(r<=high) temp.push_back(arr[r++]);
        for(int i=low; i<=high; i++) arr[i]=temp[i-low];
    }
};