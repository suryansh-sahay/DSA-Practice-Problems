class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int f1=0, f2=0, f1e, f2e;
        
        for(int num: nums){
            if(f1==0 && num!=f2e) f1e=num, f1++;
            else if(f2==0 && num!=f1e) f2e=num, f2++;
            else if(num==f1e) f1++;
            else if(num==f2e) f2++;
            else f1--, f2--;
        }
        int i=0, j=0;
        for(int num: nums){
            if(num==f1e) i++; 
            else if(num==f2e) j++;
        }
        
        vector<int> ans;
        if(i>n/3) ans.push_back(f1e);
        if(j>n/3) ans.push_back(f2e);
        return ans;
    }
};