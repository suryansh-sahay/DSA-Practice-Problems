class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,long long> freq;
        
        for(int num : nums) freq[num]++;

        long long maxi = 0;
        for(auto &x : freq){
            long long curr = x.first;

            if(curr == 1){
                maxi = max(maxi,(freq[1] % 2 == 0 ? freq[1] - 1 : freq[1]));
                continue;
            }

            long long currLen = 0;

            while(freq.count(curr) && freq[curr] >= 2){
                currLen += 2;
                curr *= curr;
            }
            if(freq.count(curr) && freq[curr] == 1) currLen++;
            else currLen--;
            maxi = max(maxi,currLen);
        }

        return maxi;
    }
};