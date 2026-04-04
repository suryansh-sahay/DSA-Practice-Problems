class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.length();
        if (len == 0) return "";
        
        int cols = len / rows;
        string ans = "";
        
        for (int j = 0; j < cols; j++) {
            for (int r = 0, c = j; r < rows && c < cols; r++, c++) {
                ans.push_back(encodedText[r * cols + c]);
            }
        }
        
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        
        return ans;
    }
};