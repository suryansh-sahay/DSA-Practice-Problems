class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<int> freq(24,0);
        long long ans=0;

        for(int i=0;i<hours.size();i++){
            int rem=hours[i]%24;
            int need=(24-rem)%24;

            ans+=freq[need];
            freq[rem]++;
        }
        return ans;
    }
};