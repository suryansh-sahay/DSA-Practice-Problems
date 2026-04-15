class Solution {
public:
    int closestTarget(vector<string>& words, string target, int st) {
        int n=words.size();
        int res=1e9;
        for(int i=0;i<n;i++){
            if(words[(st+i)%n]==target) res=min(res,i%n);
            if(words[(st-i+n)%n]==target) res=min(res,(i+n)%n);
        }
        return res==1e9?-1:res;
    }
};