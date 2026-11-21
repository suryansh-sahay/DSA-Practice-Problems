class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char c: s) mp[c]++;

        priority_queue<pair<int, char>> mp2;
        for(auto st: mp) mp2.push({st.second, st.first});

        string ans="";
        while(!mp2.empty()){
            auto [first, second]=mp2.top(); mp2.pop();
            int i=0;
            while(i<first) ans.push_back(second), i++;

        }
        return ans;
    }
};