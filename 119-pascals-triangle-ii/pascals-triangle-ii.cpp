class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> arr;

        for(int i = 0; i<=rowIndex+1; i++){
            vector<int> row(i+1, 1);
            for(int j = 1; j< i; j++){
                row[j] = (long long)(arr[i-1][j-1]) + arr[i-1][j];
            }
            arr.push_back(row);
        }
        return arr[rowIndex];
    }
};