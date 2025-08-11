class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1,suffix =1;
        int n=nums.size();
        int currMax = INT_MIN;
        for(int i=0;i<n;i++){
            if(prefix==0){
                prefix = 1;
            }
            if(suffix==0){
                suffix = 1;
            }

            prefix *= nums[i];

            int fromEnd = n - i - 1;

            suffix *= nums[fromEnd];

            

            currMax = max(currMax,max(suffix,prefix));



        }
        return currMax;
    }
};