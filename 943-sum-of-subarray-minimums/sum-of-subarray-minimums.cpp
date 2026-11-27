class Solution {
private: 
    vector<int> findnse(vector<int>& arr){
        int n=arr.size();
        vector<int> ans(n); stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
private: 
    vector<int> findpse(vector<int>& arr){
        int n=arr.size();
        vector<int> ans(n); stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[i]<arr[st.top()]) st.pop();
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=findnse(arr);
        vector<int> pse=findpse(arr);
        long long total=0, mod=1e9+7;

        for(int i=0; i<arr.size(); i++){
            int nsee=nse[i]-i;
            int psee=i-pse[i];

            total=(total+(1LL*nsee*psee*arr[i])%mod)%mod;
        }
        return (int)total;
    }
};