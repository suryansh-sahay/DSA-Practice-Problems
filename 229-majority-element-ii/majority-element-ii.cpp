class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
         int num1=INT_MIN, num2=INT_MIN, coun1=0, coun2=0;
        for(int i=0; i<n; i++){
            if(coun1==0 && nums[i]!=num2) num1=nums[i], coun1++;
            else if(coun2==0 && nums[i]!=num1) num2=nums[i], coun2++;
            else if(nums[i]==num1) coun1++;
            else if(nums[i]==num2) coun2++;
            else coun1--, coun2--;
        }
        
        coun1=coun2=0;
        for(int num: nums){
            if(num==num1) coun1++;
            else if(num==num2) coun2++;
        }

        cout<<coun1<<" "<<coun2;
        if((coun1)>n/3  && (coun2)>n/3) return {num1, num2};
        else if((coun1)>n/3) return {num1};
        else if((coun2)>n/3) return {num2};
        return {};
    }
};