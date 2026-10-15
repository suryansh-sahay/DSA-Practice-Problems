class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> arr(256, -1);
        vector<bool> arr2(256, false);
        for(int i=0; i<s.length(); i++){
           if(arr[s[i]]==-1){
               if(!arr2[t[i]])  arr[s[i]]=t[i], arr2[t[i]]=true;
               else return false;
           }
           else if(arr[s[i]]!=t[i]) return false;
        }
        return true;
    }
};
