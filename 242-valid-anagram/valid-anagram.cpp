class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> nums(26,0);
        for(char c: s) nums[c-'a']++;
        for(char c: t) nums[c-'a']--;
        for(int i:nums) if(i!=0) return false;
        return true;
    }
};