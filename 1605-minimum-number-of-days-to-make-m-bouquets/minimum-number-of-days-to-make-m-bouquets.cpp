class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()) return -1;

        int l=1, r=*max_element(bloomDay.begin(), bloomDay.end());

        while(l<r){
            int mid=l+(r-l)/2;
            if(func(bloomDay, m, k, mid)) r=mid;
            else l=mid+1;
        }
        return r;
    }
    bool func(vector<int> &arr, int m, int k, int mid){
        int total=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]<=mid){
                int count=0;
                while(i<arr.size() && arr[i]<=mid && count<k) count++, i++;
                if(count==k) total++, i--;
            }
            if(total>=m) return true;
        }
        return false;
    }
};