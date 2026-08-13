class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        
        unordered_map<int, int> con;
        
        int r=1;
        for(int num: temp){
            if(!con.count(num)) con[num]=r++;
        }
        for(int &num: arr) num=con[num];

        return arr;
    }
};