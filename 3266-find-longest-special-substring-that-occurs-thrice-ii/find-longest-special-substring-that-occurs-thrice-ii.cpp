class Solution {
public:
    int maximumLength(string s) {
 
        vector<vector<int>>v(26, vector<int>(3, -1));
        int n = s.size();
        int prevChar = s[0];
        int cnt = 1;
        for(int i = 1 ; i < n ; i ++){
            if(prevChar != s[i]){
                int idx = prevChar - 'a';
                if(cnt > v[idx][0]){
                    v[idx][0] = cnt;
                    sort(v[idx].begin() , v[idx].end());
                }
                cnt = 1;
                prevChar = s[i];
            }
            else{
                cnt ++;
            }
        }
       
        int idx = prevChar - 'a';
        if(cnt > v[idx][0]){
            v[idx][0] = cnt;
            sort(v[idx].begin() , v[idx].end());
        }

           
        int ans = -1;
        for(int i = 0; i < 26; i ++){
       
            if(v[i][0] == v[i][1] && v[i][2] == v[i][1]){
                ans = max(ans, v[i][2]);
            }

            if(v[i][1] + 1 == v[i][2] || v[i][1] == v[i][2]){
                ans = max(ans, v[i][2] - 1);
            }

            ans = max(ans, v[i][2] - 2);

            ans = max(ans, v[i][0]);
        }
        return ans == 0 ? -1 : ans;
     
     //hope you like it !

    }
};