class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0, j=matrix[0].size()-1;
        while(i<matrix.size() && j>=0){
            int val=matrix[i][j];
            if(target==val) return true;
            else if(target<val) j--;
            else i++;
        }
        return false;
    }
};