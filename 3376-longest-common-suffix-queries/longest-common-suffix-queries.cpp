class Solution {
public:
    int mod = 1e9 + 7;
    int mod2 = 1e9 + 9;
    
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        
        map<pair<int, int>, pair<int, int>> mp;
        long long hash1 = 0, hash2 = 0;
        
        int c = wordsContainer.size();
        int q = wordsQuery.size();
        vector<int> res(q, -1);
        int minn = 0;
        int mins = INT_MAX;
        for(int i = 0; i < c; i++){
            string word = wordsContainer[i];
            int n = word.size()-1;
            if(mins > n){
                mins = n;
                minn = i;
            }
            hash1 = 0, hash2 = 0;
            for(int j = n; j >= 0; j--){
                hash1 = ((hash1 * 31) % mod + (word[j] - 'a' + 1)) % mod;
                hash2 = ((hash2 * 37) % mod2 +(word[j] - 'a' + 1)) % mod2;
                if(mp.find({hash1, hash2}) == mp.end()){
                    mp[{hash1, hash2}] = {n, i};
                } else {
                    if(mp[{hash1, hash2}].first > n)
                        mp[{hash1, hash2}] = {n, i};
                }
            }
        }
        
        for(int i = 0; i < q; i++){
            string word = wordsQuery[i];
            int n = word.size()-1;
            hash1 = 0, hash2 = 0;
            for(int j = n; j >= 0; j--){
                hash1 = ((hash1 * 31) % mod + (word[j] - 'a' + 1)) % mod;
                hash2 = ((hash2 * 37) % mod2 + (word[j] - 'a' + 1)) % mod2;
                if(mp.find({hash1, hash2}) != mp.end()){
                    res[i] = mp[{hash1, hash2}].second;
                }
            }
            
            if(res[i] == -1)
                res[i] = minn;
                
        }
        cout << minn;
        
        return res;
    }
};