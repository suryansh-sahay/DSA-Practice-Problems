class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        sort(special.begin(), special.end());
        
        int ans = max((special[0]-bottom), (top-special[special.size()-1]));  
        int count  = 0;
        for(int i=0;i<special.size()-1;i++){
            count = special[i+1]-special[i]-1;
            ans=max(count,ans);
        }
        
        return ans;
    } 
};