class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string pr=strs[0];
        int n=pr.length();
        for(int i=1; i<strs.size(); i++){
            string s=strs[i];
            while(n>s.length() || pr!=s.substr(0, n)){
                n--;               
                if(n<0) return ""; 
                pr=pr.substr(0, n);
            }
        }
        return pr;
    }
};