class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size(), ans=0;
        for(int i=0; i<k; i++) ans+=arr[i];
        
        int i=k-1, sum=ans;
        while(i>=0){
            sum+=arr[n-k+i], sum-=arr[i];
            ans=max(ans, sum);
            i--;
        }
        return ans;
    }
};