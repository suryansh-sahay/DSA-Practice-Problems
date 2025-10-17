class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0; i<n; i++){
            vector<int> freq(26,0);
            for(int j=i; j<n; j++){
                freq[s[j]-'a']++;
                int maxi=0, mini=500; 
                for(int val: freq){
                    if(val>0){
                        maxi=max(maxi, val);
                        mini=min(mini, val);
                    }
                }
                sum+=maxi-mini;
            }
        }
        return sum;
    }
};