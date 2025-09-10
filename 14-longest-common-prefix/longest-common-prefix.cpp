class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=1; i<strs.size(); i++){
            int j=0;
            string temp="";
            for(char c: strs[i]){
                if(c==ans[j]) temp+=c, j++;
                else break;
            }
            ans=temp;
        }    
        return ans;    
    }
};