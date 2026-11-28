class Solution {
public:
    bool ispal(string s, int l, int r){
        while(l<=r){
            if(s[l]!=s[r]) return false;
            l++, r--;
        }
        return true;
    }
    void func(int idx, string s, vector<string>& path, vector<vector<string>>& ans){
        if(idx==s.length()){
            ans.push_back(path);
            return;
        }
        for(int i=idx; i<s.length(); i++){
            if(ispal(s, idx, i)){
                path.push_back(s.substr(idx, i+1-idx));
                func(i+1, s, path, ans);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;
        func(0, s, path, ans);
        return ans;
    }
};