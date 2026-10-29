class Solution {
public:
    static int d_sum(int s){
        int sum = 0 ;
        while(s){
            sum+=s%10 ;
            s/=10 ;
        }
        return sum ;
    }
    static bool comp(int &a,int &b){
        int s1 = d_sum(a), s2 = d_sum(b);
        if(s1!=s2)return s1<s2;
        return a<b ;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size() ;

        unordered_map<int,int>um;

        for(int i=0;i<n;i++)um[nums[i]]=i;

        vector<int>v=nums ;
        sort(v.begin(),v.end(),comp);
        int cnt = 0 ;
        
        for(int i=0;i<n;i++){
            if(nums[i]!=v[i]){
                cnt++;
                int p = um[v[i]] ;
                nums[p]=nums[i];
                um[v[i]]=i;
                um[nums[i]]=p;
            }
        }
        return cnt ;
    }
};