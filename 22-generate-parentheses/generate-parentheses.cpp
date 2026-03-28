class Solution {
public:
    void func(int l, int r, string st, vector<string>& ans){
        if(l==0 && r==0){
            ans.push_back(st);
            return;
        }
        else if(l==r){
            func(l-1, r, st+'(', ans);
        }
        else if(l==0){
           func(l, r-1, st+')', ans);
        }   
        else{
            string op1=st+'(';
            func(l-1, r, op1, ans);
            func(l, r-1, st+')', ans);
        }
    } 
    vector<string> generateParenthesis(int n) {
       int l=n, r=n;
       string st="";
       vector<string> ans;
       func(l, r, st, ans);
       return ans;
    }
};