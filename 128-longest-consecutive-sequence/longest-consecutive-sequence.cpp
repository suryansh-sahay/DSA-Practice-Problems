class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> check(nums.begin(), nums.end());

        int maxi=0;
        for(int num: check){
            if(check.find(num-1)==check.end()){
                int temp=1;
                while(check.find(++num)!=check.end()) temp++;
                maxi=max(maxi, temp);
            }
        }
        return maxi;
    }
};