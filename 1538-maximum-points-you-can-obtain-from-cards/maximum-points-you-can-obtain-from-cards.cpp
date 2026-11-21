class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int res = 0;
		
        for(int i=0;i<k;i++) res+=arr[i];
        
        int curr=res;
        for(int i=k-1;i>=0;i--) {
            curr-=arr[i];
            curr+=arr[arr.size()-k+i];
			
			res = max(res, curr);
        }
        
        return res;
    }
};