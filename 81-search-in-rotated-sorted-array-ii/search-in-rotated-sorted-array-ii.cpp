class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int l=0, r=arr.size()-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(arr[mid]==target) return true;
            if(arr[mid]==arr[r]) {r--; continue;}
            if(arr[mid]<arr[r]){
                if(target<=arr[r] && target>arr[mid]) l=mid+1;
                else r=mid-1;
            }
            else{
                if(target<arr[mid] && target>=arr[l]) r=mid-1;
                else l=mid+1;
            }
        }
        return false;
    }
};