class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        int i=0, j=1; 
        for(int num: nums){
            if(num>0) temp[i]=num, i+=2;
            else temp[j]=num, j+=2;
        }
        return temp;
    }
};