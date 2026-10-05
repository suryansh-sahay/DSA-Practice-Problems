class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> arr(100,0);
        int maxi=0, freq=0, no=0;
        for(int num: nums){
            arr[num-1]++;
            if(arr[num-1]>maxi) maxi=arr[num-1], freq=1;
            else if(arr[num-1]==maxi) freq++;
        }
        return maxi*freq;
    }
};