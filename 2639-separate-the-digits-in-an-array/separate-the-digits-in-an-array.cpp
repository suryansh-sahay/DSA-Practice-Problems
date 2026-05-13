class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int num: nums){
           string str=to_string(num);
           for(int i=0; i<str.length(); i++){
            ans.push_back(str[i]-'0');
            cout<<str[i]<<" ";
           }
           cout<<endl;
        } 
        return ans;
    }
};