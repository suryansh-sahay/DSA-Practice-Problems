class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return ms(nums, 0, nums.size()-1);
    }
    int ms(vector<int>& nums, int l, int r){
        if(l>=r) return 0;
        int mid=l+(r-l)/2;
        int ans=0;
        ans+=ms(nums, l, mid);
        ans+=ms(nums, mid+1, r);
        ans+=merge(nums, l, mid, r);
        return ans;
    }
    int merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int l=low, r=mid+1;
        while(l<=mid && r<=high){
            if(nums[l]<=nums[r]) temp.push_back(nums[l]), l++;
            else temp.push_back(nums[r]), r++;
        }
        while(l<=mid) temp.push_back(nums[l]), l++;
        while(r<=high) temp.push_back(nums[r]), r++;

        l=low, r=mid+1;
        int ans=0;
        while(l<=mid && r<=high){
            if(nums[l]>(long long)2*nums[r]) ans+=mid-l+1, r++;
            else l++;
        }

        for(int i=0; i<temp.size(); i++) nums[i+low]=temp[i];
        return ans;
    }
};