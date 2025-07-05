class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> data;
        for(int i=0; i<arr.size(); i++){
            data[arr[i]]++;
        }
        int ans=-1;
        for(auto& [num, freq] : data){
            if(num==freq) ans=max(ans, num);
        }
        // for(int i=1; i<data.size(); i++){
        //     if(data[i]==i) ans=max(ans, data[i]);
        // }
        return ans;
    }
};