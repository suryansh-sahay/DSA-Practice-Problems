class Solution {
public:
    int findLHS(vector<int>& a) {
        sort(a.begin(),a.end());
        int j=0,l=0,n=a.size();
        for(int i=1;i<n;++i)
            if(a[i]-a[j]>1) {
                if(a[i-1]-a[j]==1)
                    l=max(l,i-j);
                for(;j<n&&a[i]-a[j]>1;++j);
            }
        if(a[n-1]-a[j]==1)
            l=max(l,n-j);
        return l;
    }
};