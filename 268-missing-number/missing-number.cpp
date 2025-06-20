class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();
        int total =n*(n+1)/2;
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        return (total-sum);

        // vector<bool> check(n+1, false);
        // for(int i=0; i<n; i++){
        //     check[nums[i]]=true;
        // }
        
        // int val;
        // for(int i=0; i<n+1; i++){
        //     if(check[i]==false) {val=i; break;}
        // }
        
        // return val;
    }
};