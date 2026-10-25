class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ch(nums.begin(), nums.end());

        int ans=0;
        
        for(int num: ch){
            if(!ch.count(num-1)){
                int count=1;
                while(ch.count(num+1)) count++, num++;
                ans=max(ans, count);
            }
        }
        return ans;
    }
};