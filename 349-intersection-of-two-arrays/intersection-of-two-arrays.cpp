class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> freq(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;

        int temp=-1;
        for(int num: nums2){
            if(temp!=num && freq.count(num)){
                ans.push_back(num);
            }
            temp=num;
        }
        return ans;
    }
};