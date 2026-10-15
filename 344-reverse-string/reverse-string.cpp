class Solution {
public:
    void reverseString(vector<char>& s) {
        func(s, 0, s.size()-1);
    }
    void func(vector<char>&s, int i, int j){
        if(i>=j) return;
        swap(s[i], s[j]);
        return func(s, i+1, j-1);
    }
};