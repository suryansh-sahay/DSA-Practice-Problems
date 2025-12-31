int dfs(vector<vector<int>>&grid,int i,int j)
{
    int m=grid.size();
    int n=grid[0].size();
    if(i<0 or j<0 or i>=m or j>=n or grid[i][j]==0)
    return 0;
    grid[i][j]=0;
    int area=1;
    area=area+dfs(grid,i+1,j);
    area=area+dfs(grid,i-1,j);
    area=area+dfs(grid,i,j+1);
    area=area+dfs(grid,i,j-1);
  return area;
}
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxarea=0;
        if(grid.empty())
        return 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                   int area= dfs(grid,i,j);
                    maxarea=max(area,maxarea);
                }

            }
        }
        return maxarea;
        
    }
};