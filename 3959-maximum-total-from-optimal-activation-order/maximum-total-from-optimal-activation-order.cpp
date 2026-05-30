class Solution {
    private:
    struct Compare{
        bool operator()(const pair<int, int> & a, const pair<int, int> & b){
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        }
    };
    public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        int n = value.size();
        for(int i=0; i<n; i++) pq.push({limit[i], value[i]});
        queue<int> activeLimits;
        long long ans = 0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int topLimit = top.first; 
            int topValue = top.second;
            int currentActive = activeLimits.size();
            if(topLimit > currentActive){
                ans += topValue;
                activeLimits.push(topLimit);
                if(!activeLimits.empty() && currentActive >= activeLimits.front()){
                    activeLimits.pop();
                }
            }
        }
        return ans;
    }
};