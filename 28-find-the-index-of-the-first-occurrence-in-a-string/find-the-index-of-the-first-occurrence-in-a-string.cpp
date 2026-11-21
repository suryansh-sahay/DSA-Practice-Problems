class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.length(), n=needle.length();
        if(m<n) return -1;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(haystack[i+j]!=needle[j]) break;
                if(j==n-1) return i;
            }
        }
        return -1;
    }
};