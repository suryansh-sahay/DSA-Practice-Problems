class Solution {
public:
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<int> g(m * n);
        for (auto& pos : walls) g[pos[0] * n + pos[1]] = 2;
        for (auto& pos : guards) g[pos[0] * n + pos[1]] = 2;
        for (auto& pos : guards)
            for (int i = 0, d[] = {1,0,-1,0,0,1,0,-1}; i < 7; i += 2) 
                for (int y = pos[0] + d[i], x = pos[1] + d[i + 1];
                    y >= 0 && y < m && x >= 0 && x < n && g[y * n + x] < 2;)
                        g[y * n + x] = 1, y += d[i], x += d[i + 1];
        return count_if(g.begin(), g.end(), [](int v){ return v < 1; }); 
    }
};