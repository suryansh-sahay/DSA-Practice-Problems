class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2) return n;
        
        int ans=0;
        for(auto pt1: points){
            double x1= pt1[0], y1=pt1[1];
            unordered_map<double, int> slpe;

            for(auto pt2: points){
                if(pt1!=pt2){
                    double slp;
                    double x2= pt2[0], y2=pt2[1];
                    if(x2==x1) slp=INT_MAX;
                    else slp=(y2-y1)/(x2-x1);
                    slpe[slp]++;
                    ans= max(ans, slpe[slp]);
                }
            }
        }
        return ans+1;
    }
};