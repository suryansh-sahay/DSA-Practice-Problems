class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double mdiag=INT_MIN;
        int area=INT_MIN;
        
        for(int i=0; i<dimensions.size(); i++){
            int l=dimensions[i][0];
            int w=dimensions[i][1];
            
            double diag=l*l+w*w;
            if(diag>mdiag || (diag==mdiag && l*w>area)) mdiag=diag, area=l*w;
        }
        return area;
    }
};