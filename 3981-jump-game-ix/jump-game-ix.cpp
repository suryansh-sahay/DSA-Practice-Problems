class Solution {
public:
    vector<int> maxValue(vector<int>& a) {
        int n = a.size();
        if (n == 0) return {};
        vector<int> p(n), s(n), ans(n);

        for (int i = 0; i < n; ++i) 
            p[i] = (i ? max(p[i-1], a[i]) : a[i]);

        s[n-1] = a[n-1];
        for (int i = n-2; i >= 0; --i) 
            s[i] = min(s[i+1], a[i]);

        ans[n-1] = p[n-1];
        for (int i = n-2; i >= 0; --i) 
            ans[i] = (p[i] > s[i+1]) ? ans[i+1] : p[i];

        return ans;
    }
};