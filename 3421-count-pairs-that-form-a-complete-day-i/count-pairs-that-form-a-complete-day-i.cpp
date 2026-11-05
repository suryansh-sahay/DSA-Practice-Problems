class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int c = 0;
        int n = hours.size();
        for(int i = 0; i < n-1; i++) for(int j = i; j < n; j++) if((hours[i] + hours[j]) % 24 == 0 && i < j) c++;
        return c;
    }
};