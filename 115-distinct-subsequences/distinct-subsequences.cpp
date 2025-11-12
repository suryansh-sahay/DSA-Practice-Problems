class Solution {
public:
    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        vector<double> prev(n2+1,0);
        prev[0]=1;
        for(int i=1;i<n1+1;i++){
            for(int j=n2;j>=1;j--){
                if(s[i-1]==t[j-1]){
                    prev[j]=prev[j-1]+prev[j];
                }
            }
        }
        return int(prev[n2]);
    }
};