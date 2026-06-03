class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int n=landStartTime.size(), m=waterStartTime.size();
         int minL=3e5+1, minW=3e5+1;

        for(int i=0; i<n; i++){
           minL=min(landStartTime[i]+landDuration[i], minL);
        }
        for(int i=0; i<m; i++){
           minW=min(waterStartTime[i]+waterDuration[i], minW);
        }
        int ansL=3e5+1, ansW=3e5+1;

        for(int i=0; i<m; i++){
            ansL=min(ansL, max(minL,waterStartTime[i])+waterDuration[i]);
        }

        for(int i=0; i<n; i++){
            ansW=min(ansW, max(minW, landStartTime[i])+landDuration[i]);
        }    
        return min(ansL, ansW);
    }
};