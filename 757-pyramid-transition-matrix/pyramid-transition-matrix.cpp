class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mapping;
        for (const string& triple : allowed){
            string key = triple.substr(0, 2);
            mapping[key].push_back(triple[2]);
        }
        unordered_map<string, bool> memo;
        function<bool(const string&)> DFS = [&](const string& row) -> bool {
            auto it = memo.find(row);
            if (it != memo.end())
                return it->second;
            if (row.size() == 1)
                return memo[row] = true;
            int n = (int)row.size();
            for (int i = 0; i < n - 1; i++){
                string pair = row.substr(i, 2);
                if (mapping.find(pair) == mapping.end()){
                    return memo[row] = false;
                }
            }
            function<bool(int, string&)> buildNext = [&](int i, string& nextRow) -> bool {
                if (i == n - 1){
                    return DFS(nextRow);
                }
                string pair = row.substr(i, 2);
                auto mit = mapping.find(pair);
                if (mit == mapping.end())
                    return false;
                for (char c : mit->second){
                    nextRow.push_back(c);
                    if (buildNext(i + 1, nextRow))
                        return true;
                    nextRow.pop_back();
                }
                return false;
            };
            string nextRow;
            bool good = buildNext(0, nextRow);
            memo[row] = good;
            return good;
        };
        return DFS(bottom);
    }
};