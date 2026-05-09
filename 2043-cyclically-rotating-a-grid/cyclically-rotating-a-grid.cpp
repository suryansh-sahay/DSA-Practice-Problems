class Solution {
public:
    struct Griderator {
        std::vector<std::vector<int>>& grid;
        int r, c;
        int rMin, rMax, cMin, cMax;
        
        Griderator(std::vector<std::vector<int>>& g, int lvl) : grid(g) {
            rMin = lvl;
            cMin = lvl;
            rMax = g.size() - 1 - lvl;
            cMax = g.front().size() - 1 - lvl;
            r = rMin;
            c = cMin;
        }

        Griderator(std::vector<std::vector<int>>& g, int lvl, int startR, int startC) 
            : Griderator(g, lvl) {
            r = startR;
            c = startC;
        }

        std::pair<int, int> getPos() const { return {r, c}; }

        void operator++() {
            if (c == cMin && r < rMax) r++;     
            else if (r == rMax && c < cMax) c++; 
            else if (c == cMax && r > rMin) r--;
            else if (r == rMin && c > cMin) c--; 
        }

        int& operator*() { return grid[r][c]; }
    };

    std::vector<std::vector<int>> rotateGrid(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid.front().size();
        int numLayers = std::min(m, n) / 2;

        for (int lvl = 0; lvl < numLayers; ++lvl) {
            int h = m - 2 * lvl;
            int w = n - 2 * lvl;
            int total = 2 * (h + w) - 4;
            
            int shift = k % total;
            if (shift == 0) continue;

            std::vector<int> layer;
            layer.reserve(total);
            
            Griderator readIt(grid, lvl);
            int ins_i = readIt.r, ins_j = readIt.c; 
            
            for (int i{}; i < total; ++i) {
                layer.push_back(*readIt);
                ++readIt;
                
                if (--shift == 0) {
                    std::tie(ins_i, ins_j) = readIt.getPos();
                }
            }

            Griderator writeIt(grid, lvl, ins_i, ins_j);
            for (int val : layer) {
                *writeIt = val;
                ++writeIt;
            }
        }

        return grid;
    }
};