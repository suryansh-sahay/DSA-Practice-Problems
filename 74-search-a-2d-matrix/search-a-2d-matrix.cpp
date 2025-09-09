class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int l=0, r=m*n-1; 

        while(l<=r){
            int mid=l+(r-l)/2;
            int row=mid/m, clmn=mid%m;
            if(matrix[row][clmn]==target) return true;
           else if(matrix[row][clmn]<target) l=mid+1;
            else r=mid-1;
        }
        return false;
    }
};