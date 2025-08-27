class Solution {
public:
    int getsum(vector<int>& nums, int mid){
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += (nums[i] + mid -1)/mid;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int start = 1;
        int end = *max_element(nums.begin(),nums.end());
        int ans = end;
        while(start<=end){
            int mid = start + (end- start)/2;
            int sum = getsum(nums,mid);
            if(sum<=threshold){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            } 
        }
        return ans;
    }
};