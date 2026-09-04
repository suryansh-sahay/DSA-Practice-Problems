class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=*min_element(nums.begin(), nums.end());
        int maxi=*max_element(nums.begin(), nums.end());

        while(mini!=0){
            int temp=mini;
            mini=maxi % mini;
            maxi=temp;
        }
        return maxi;
    }
};