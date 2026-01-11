class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> freq;
        vector<int> C;
        int temp=0;
        for(int i=0; i<B.size(); i++){
           freq[A[i]]++;
           if(freq[A[i]]==2) temp++;
           freq[B[i]]++;
           if(freq[B[i]]==2) temp++;
           C.push_back(temp);
        }
        return C;
    }
};