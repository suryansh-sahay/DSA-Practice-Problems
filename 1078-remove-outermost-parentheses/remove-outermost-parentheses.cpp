class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int count=0; 
        for(char c: s){
            if(c=='('){
               count++; 
               if(count>1) ans+=c;
            }
            else{
                if(count>1) ans+=c;
                count--;
            }
        }
        return ans;
    }
};