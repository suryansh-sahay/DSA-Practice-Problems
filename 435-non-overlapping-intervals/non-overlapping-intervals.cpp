class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        int j=0, count=1;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>=intervals[j][1]) j=i, count++;
        }
        return n-count;
    }
};