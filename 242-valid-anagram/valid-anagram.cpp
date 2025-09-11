class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr(26,0);
        for(char c: s){
            arr[c-'a']++;
        }
        for(char c: t) arr[c-'a']--;
        for(int i:arr) if(i!=0) return false;
        return true;
    }
};