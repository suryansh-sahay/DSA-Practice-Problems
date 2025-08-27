class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        int n=bloomDay.size();
        if((long long)m*k > n) return -1;
        int l=*min_element(bloomDay.begin(), bloomDay.end());
        int r=*max_element(bloomDay.begin(), bloomDay.end());

        while(l<r){
            int mid=l+(r-l)/2;
            int count=0, m2=0; 
            for(int num: bloomDay){
                if(num<=mid) count++;
                else count=0;
                if(count==k) m2++, count=0;
            }
            if(m2>=m) r=mid;
            else l=mid+1;
        }
        return r;
    }
};