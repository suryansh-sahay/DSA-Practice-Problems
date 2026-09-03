class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=*min_element(nums1.begin(), nums1.end());
        if(mini%2==1) return true;

        int count=0;
        for(int i: nums1) if(i%2==1) count++; 
        return count==0;       
    }
};
