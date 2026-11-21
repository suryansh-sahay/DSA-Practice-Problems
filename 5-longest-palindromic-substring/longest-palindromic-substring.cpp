class Solution {
public:
    string longestPalindrome(string s) {
        string ans=""; int maxi=0;

        for(int i=0; i<s.length(); i++){
            string odd=maxstr(s, i, i);
            string even=maxstr(s, i-1, i);

            if(odd.length()>ans.length()) ans=odd;
            else if (even.length()>ans.length()) ans=even;
        }
        return ans;
    }

private:
    string maxstr(string& s, int start, int end){
        while(start>=0 && end<s.length() && s[start]==s[end]) start--, end++;
        return s.substr(start+1, end-start-1); 
    }
};