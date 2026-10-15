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
        return merge(arr, l, mid, h);
    }
    void merge(vector<int>& arr, int l, int mid, int h){
        vector<int> temp;
        int left=l, right=mid+1;
        while(left<=mid && right<=h){
            if(arr[left]<=arr[right]) temp.push_back(arr[left++]);
            else temp.push_back(arr[right++]);
        }
        while(left<=mid) temp.push_back(arr[left++]);
        while(right<=h) temp.push_back(arr[right++]);

        for(int i=l; i<=h; i++) arr[i]=temp[i-l];
    }
};