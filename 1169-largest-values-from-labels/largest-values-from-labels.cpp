class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++){
            pq.push({values[i], labels[i]});
        }
         
        int count = 0, res=0;
        while(count < numWanted && !pq.empty()){
            auto i = pq.top();
            pq.pop();

            int value = i.first;
            int label = i.second;

            if(mp[label] < useLimit){
                mp[label]++;
                res += value;
                count++;
            }
        }
        return res;
    }
};