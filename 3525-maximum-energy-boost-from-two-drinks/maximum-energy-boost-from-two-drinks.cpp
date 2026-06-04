class Solution {
public:
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
        long long a0 = 0, a1 = 0, b0 = 0, b1 = 0, n = A.size();
        for (int i = 0; i < n; i++) {
            a1 = max(a0 + A[i], b0);
            b1 = max(b0 + B[i], a0);
            a0 = a1; b0 = b1;
        }
        return max(a1, b1);
    }
};