class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<int>behind(10, 0);    

        for(int i=n-1; i>=0; i--){  
            vector<int>curr(10, INT_MAX);

            vector<int>freq(10, 0);
            for(int j=0; j< m; j++){
                freq[grid[j][i]]++;
            }
            for(int j=0; j< 10; j++){
                for(int k=0; k< 10; k++){
                    if(j==k) continue;
                    curr[j]= min(curr[j] , (m- freq[j]) + behind[k]);
                }
            }
            behind= curr;
        }
        int ans= INT_MAX;
        for(int i=0; i< 10; i++){
            ans= min(ans , behind[i]);

        }
        return ans;
    }
};