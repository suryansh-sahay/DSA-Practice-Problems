class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> arr;
        for(int val: nums) arr.insert(val);

        int val=k;
        while(true){
        if(arr.find(val)==arr.end()) return val;
            val+=k;
        }
        
    }
};