class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();

        for(int i=0; i<n; i++){
            int k=i+1, j=n-1;
            int presum=target-numbers[i];
            cout<<presum<<" ";
            while(k<=j){
                int mid=k+(j-k)/2;
                if(numbers[mid]==presum) return {i+1,mid+1};
                else if(numbers[mid]>presum) j=mid-1;
                else k=mid+1;
            }
        }
        return {};
    }
};