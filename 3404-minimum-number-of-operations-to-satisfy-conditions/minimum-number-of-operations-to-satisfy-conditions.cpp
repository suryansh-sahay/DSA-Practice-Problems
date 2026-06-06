class Solution {
public:
    
    int solve(int col, int n, int m, int prev, vector<vector<int>> &freq, vector<vector<int>> &memo){
        if(col == m) return 0;
        
        if(memo[col][prev+1] != -1) return memo[col][prev+1];
        
        int c=INT_MAX/2;
        for(int num=0;num<=9;num++){
            if(num != prev) c = min(c, n-freq[col][num] + solve(col+1, n, m, num, freq, memo));
        }
        
        return memo[col][prev+1] = c;
    }
    
    int minimumOperations(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<int>> freq(m, vector<int> (10,0));
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                freq[j][grid[i][j]]++;
            }
        }
        
        vector<vector<int>> memo(m ,vector<int> (11, -1));
        
        return solve(0, n, m, -1, freq, memo);
    }
};