class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> quan(101,0); //frequency
        int maxi=0;
        int num=0;
        for(int i=0; i<nums.size(); i++){
            quan[nums[i]]++;
            if(maxi == quan[nums[i]]) num++;
            else if(maxi < quan[nums[i]]) maxi=quan[nums[i]], num=1;
        }
        return num*maxi;
    }
};