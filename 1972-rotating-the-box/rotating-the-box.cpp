class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for(int i = 0;i<m;i++){
            int x = n - 1;
            for(int j = n-1;j>=0;j--){
                if(boxGrid[i][j]=='#'){
                    ans[x][m-i-1] = '#';
                    x--;
                }
                else if(boxGrid[i][j]=='*'){
                    ans[j][m-i-1] = '*';
                    x = j - 1;
                }
            }
        }

        return ans;
    }
};