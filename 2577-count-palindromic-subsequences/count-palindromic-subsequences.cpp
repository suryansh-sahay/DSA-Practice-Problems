class Solution {
public:
    const int MOD = 1e9+7; 
    int f(int i, int size, vector<char>& pattern, string& s, vector<vector<int>>& dp){
        if(size==5) return 1;
        if(i>=s.size()) return 0;
        if(dp[i][size] != -1) return dp[i][size];
        int pick1 = 0;
        int pick2 = 0;
        if(s[i]==pattern[size] || (size==2)) pick1 = f(i+1, size+1, pattern, s, dp);
        
        pick2 = f(i+1, size, pattern, s, dp);
        return dp[i][size] = pick1%MOD+pick2%MOD;

    }
    int countPalindromes(string& s) {
        int n = s.size();
        int count = 0;
        for(int i=0; i<=9; i++){
            for(int j=0; j<=9; j++){
                char x = '0'+i;
                char y = '0'+j;
                vector<vector<int>> dp(n, vector<int>(5, -1));
                vector<char> pattern = {x, y, '0', y, x};
                count  = (count%MOD + f(0, 0, pattern, s, dp)%MOD)%MOD;
            }
        }

        return count;
    }
};