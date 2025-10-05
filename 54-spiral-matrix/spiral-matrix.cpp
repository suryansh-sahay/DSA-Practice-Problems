class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> nums;
        int m=matrix.size()-1;
        int n=matrix[0].size()-1;
        
        int top=0, left=0, bottom=m, right=n;
        
        while(top<=bottom && left<=right){
            for(int i=left; i<=right; i++) nums.push_back(matrix[top][i]);
            top++; 
            for(int i=top; i<=bottom; i++) nums.push_back(matrix[i][right]);
            right--;
            if(top<=bottom){
                for(int i=right; i>=left; i--) nums.push_back(matrix[bottom][i]);
                bottom--;
            }

            if(left<=right){
                for(int i=bottom; i>=top; i--) nums.push_back(matrix[i][left]);
                left++;
            }

        }
        return nums;
    }
};