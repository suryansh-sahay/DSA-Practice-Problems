class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size()-1, n=matrix[0].size()-1;
        vector<int> ans;
        int i=0, j=0;
        while(i<=m && j<=n){
            for(int y=j; y<=n; y++) ans.push_back(matrix[i][y]); i++;
            for(int x=i; x<=m; x++) ans.push_back(matrix[x][n]); n--;

            if(i<=m) for(int y=n; y>=j; y--) ans.push_back(matrix[m][y]); m--;
            if(j<=n) for(int x=m; x>=i; x--) ans.push_back(matrix[x][j]); j++;
        }
        return ans;
    }
};