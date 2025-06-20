class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();
        // sort(nums.begin(), nums.end());  // nlogn
        // int left=0, right=n;
        // while(left<right){
        //    int mid=left+(right-left)/2;
        //    if(nums[mid]>mid) right=mid;
        //    else{left=mid+1;}
        // }
        // return left;

        int sum=n;
        for(int i=0; i<n; i++){
            sum=sum+i-nums[i];
        }
        return sum;

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