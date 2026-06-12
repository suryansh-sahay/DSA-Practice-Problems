class Solution {
public:
vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
    vector<int> ans(groups.size(), -1);
    unordered_map<int,int> eleIndex;
    for(int i = 0; i < elements.size(); ++i) eleIndex[elements[i]] = (eleIndex.find(elements[i]) != eleIndex.end())? min(eleIndex[elements[i]], i): i;
    for(int i = 0; i < groups.size(); ++i){ 
        for(int f = 1; f*f <= groups[i]; ++f){
            if(groups[i] % f == 0 && eleIndex.find(f) != eleIndex.end()) ans[i] = min(((ans[i] >= 0)?ans[i]:INT_MAX), eleIndex[f]);
            if(groups[i] % f == 0 && eleIndex.find(groups[i]/f) != eleIndex.end()) ans[i] = min(((ans[i] >= 0)?ans[i]:INT_MAX), eleIndex[groups[i]/f]);
        }
    }
    return ans;
}
};