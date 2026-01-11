class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        unordered_set<int> freq1, freq2;
        vector<int> C;
        int temp=0;
        for(int i=0; i<B.size(); i++){
            freq1.insert(A[i]), freq2.insert(B[i]);
            if(A[i]==B[i]) temp++;
            else{
            if(freq1.count(B[i])) temp++;
            if(freq2.count(A[i])) temp++;
            }
            C.push_back(temp);
        }
        return C;
    }
};