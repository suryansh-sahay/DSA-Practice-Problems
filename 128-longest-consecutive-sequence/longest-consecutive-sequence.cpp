class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> check(nums.begin(), nums.end());

        int  ans=0, leng=1;
        for(int num: check){
               if(!check.count(num-1)){
                    while(check.count(num+1)){
                        leng++, num++;
                    }
                    ans=max(ans,leng);
               }
            leng=1;
        }  
        return ans;
    }
};