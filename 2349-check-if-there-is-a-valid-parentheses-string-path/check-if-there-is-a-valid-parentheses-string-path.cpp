static int dp[100][100][201];
class Solution {
private:
    int m, n;
    bool dfs(vector<vector<char>>& grid , int i , int j , int k){
        if(i == m || j == n) return 0;
        k += (grid[i][j] == '(') ? 1 : -1;
        if(k < 0 || k >= (m + n - 1 - i - j)) return 0;
        if(i == m - 1 && j == n - 1) return k == 0;
        int& res = dp[i][j][k];
        if(res != -1) return res;
        return res = dfs(grid , i + 1 , j , k) | dfs(grid , i , j + 1 , k);
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        if((m + n - 1) & 1) return false;
        if(grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;
        memset(dp , -1 , sizeof(dp));
        return dfs(grid , 0 , 0 , 0);
    }
};