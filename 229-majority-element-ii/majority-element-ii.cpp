class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int c1=0, c2=0;
        int ele1, ele2;

        for(int num: nums){
            if(c1==0 && num!=ele2) ele1=num, c1=1;
            else if(c2==0 && num!=ele1) ele2=num, c2=1;
            else if(num==ele1) c1++;
            else if(num==ele2) c2++;
            else c1--, c2--;
        }
        int t1=0, t2=0;
        for(int num: nums){
            if(num==ele1) t1++;
            else if(num==ele2) t2++;
        }
        vector<int> ans;
        if(t1>(n/3)) ans.push_back(ele1);
        if(t2>(n/3)) ans.push_back(ele2);
        return ans;
    }
};