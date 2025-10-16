class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        int l=0, r=n-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            int row=0; 
            for(int i=0; i<m; i++){
                if(mat[row][mid]<mat[i][mid]) row=i;
            }
            int val=mat[row][mid];
            if((mid==0 || val>mat[row][mid-1]) && (mid==n-1 || val>mat[row][mid+1])) return {row, mid};
            else if(mid>0&&val<mat[row][mid-1]) r=mid-1;
            else l=mid+1;
        }
        return {-1, -1};
    }
};
