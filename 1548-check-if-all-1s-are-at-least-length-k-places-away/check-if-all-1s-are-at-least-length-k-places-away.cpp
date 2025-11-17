class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n2=-1e7;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                if(i-n2-1 < k) return false;
                n2=i;
            }
        }
        return true;
    }
};