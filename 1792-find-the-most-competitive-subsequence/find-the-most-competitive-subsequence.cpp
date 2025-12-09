class Solution {
public:
    vector<int> segT;
    void build(int ind, int l, int r, vector<int>& nums){
        if(l==r){
            segT[ind] = nums[l];
            return;
        }
        int mid = l + ((r-l)/2);
        build(2*ind+1,l,mid,nums);
        build(2*ind+2,mid+1,r,nums);
        segT[ind]  = min(segT[2*ind+1],segT[2*ind+2]);
    }
    int query(int ind, int ql, int qr, int l, int r){
        if(ql<=l && r<=qr){
            return segT[ind];
        }
        if(ql > r or qr < l){
            return INT_MAX;
        }
        int mid = l + ((r-l)/2);
        return min(query(2*ind+1,ql,qr,l,mid),query(2*ind+2,ql,qr,mid+1,r));
    }
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        segT.resize(4*n);
        build(0,0,n-1,nums);
        vector<int> ans;
        int i = 0;
        while(k){
            int mini = query(0,i,n-k,0,n-1);
            ans.push_back(mini);
            while(nums[i] != mini){
                i++;
            }
            i++;
            k--;
        }
        return ans;
    }
};