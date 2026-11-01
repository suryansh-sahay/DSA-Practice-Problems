class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int maxi = 0;
        int n = nums1.size();
        for(int i = 0; i < n; i++){
            int d = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, d);
        }
        vector<int>countDiff(maxi+1, 0);
        for(int i = 0; i < n; i++){
            int d = abs(nums1[i] - nums2[i]);
            countDiff[d]++;
        }
        int k = k1 + k2;
        for(int i = maxi; i > 0 && k > 0 ; i--){
            int countOps = min(countDiff[i], k);
            countDiff[i]-= countOps;
            countDiff[i-1] += countOps;
            k-= countOps;
        }
        long long res = 0;
        for(int i = 1; i <= maxi; i++){
            res+= (1LL * countDiff[i] * i * i);
        }
        return res;
    }
};