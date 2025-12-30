class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        vector<int> seen(10, 0);
        for (int i = r; i < r + 3; i++)
            for (int j = c; j < c + 3; j++) {
                int v = g[i][j];
                if (v < 1 || v > 9 || seen[v]) return false;
                seen[v] = 1;
            }

        int s = g[r][c] + g[r][c+1] + g[r][c+2];
        for (int i = 0; i < 3; i++)
            if (g[r+i][c] + g[r+i][c+1] + g[r+i][c+2] != s) return false;
        for (int j = 0; j < 3; j++)
            if (g[r][c+j] + g[r+1][c+j] + g[r+2][c+j] != s) return false;

        return g[r][c] + g[r+1][c+1] + g[r+2][c+2] == s &&
               g[r][c+2] + g[r+1][c+1] + g[r+2][c] == s;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i + 2 < grid.size(); i++)
            for (int j = 0; j + 2 < grid[0].size(); j++)
                if (isMagic(grid, i, j)) res++;
        return res;
    }
};