class Solution {
private:
    int rows = 0;
    int cols = 0;
    int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if(row>=rows || col>=cols) return INT_MAX;
        if(dp[row][col]!=INT_MAX) return dp[row][col];
        return dp[row][col] = grid[row][col] + min(solve(row+1,col,grid,dp),solve(row,col+1,grid,dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,INT_MAX));
        dp[rows-1][cols-1]=grid[rows-1][cols-1];
        return solve(0,0,grid,dp);
    }
};