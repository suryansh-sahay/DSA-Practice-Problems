class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int is=0, ie=m-1, js=0, je=n-1;

        vector<int> ans;
        while(is<=ie && js<=je){
            for(int j=js; j<=je; j++) ans.push_back(matrix[is][j]);
            is++;
            for(int i=is; i<=ie; i++) ans.push_back(matrix[i][je]);
            je--;
            if(is<=ie){
                for(int j=je; j>=js; j--) ans.push_back(matrix[ie][j]);
                ie--;
            }
            if(js<=je){
                for(int i=ie; i>=is; i--) ans.push_back(matrix[i][js]);
                js++;
            }
        }
        return ans;
    }
};