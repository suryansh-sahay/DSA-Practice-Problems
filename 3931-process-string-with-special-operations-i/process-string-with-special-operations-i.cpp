class Solution {
public:
    string processStr(string s) {
        string result="";
        for(const char c: s){
            if(isalnum(c)) result+=c;
            else if(!result.empty() && c=='*') result.pop_back();
            else if(c=='#') result+=result;
            else if(c=='%') reverse(result.begin(), result.end());
        }
        return result;
    }
};