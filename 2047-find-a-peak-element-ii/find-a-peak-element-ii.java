class Solution {
    public int[] findPeakGrid(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;

        int l = 0 , r = m-1;

        while(l<=r){
            int mid = l + ((r-l)>>1);
            int mxrow = 0;
            int mxm = mat[mxrow][mid];
            for(int i=1;i<n;i++){
                if(mxm<mat[i][mid]){
                    mxm = mat[i][mid];
                    mxrow = i;
                }
            }

            if(mid>0 && mat[mxrow][mid-1]>mxm) r = mid-1;
            else if(mid<m-1 && mat[mxrow][mid+1]> mxm) l = mid+1;
            else return new int[]{mxrow , mid};
        }
        return new int[]{-1,-1};
    }
}