class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int mdiag=-1;
        int area=-1;
        
        for(int i=0; i<dimensions.size(); i++){
            int l=dimensions[i][0];
            int w=dimensions[i][1];
            
            double diag=l*l+w*w;
            if(diag>mdiag || (diag==mdiag && l*w>area)) mdiag=diag, area=l*w;
        }
        return area;
    }
};