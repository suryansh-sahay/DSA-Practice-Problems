class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int count=0, coun=0; 
        for(char c: s){
            if(count==0 && c=='(') {count++; continue;}
            else if(count==1 && c==')') {count--; continue;}
            else if(c=='(')count++;
            else if(c==')') count--;
            ans+=c;
        }
        return ans;
    }
};