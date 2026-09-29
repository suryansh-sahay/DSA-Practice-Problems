class Solution {
public:
    using ll=long long;

    long long splitArray(vector<int>& nums) {
        ll n = nums.size();
        vector<bool> sieve(n, true);

        if (n > 0) sieve[0] = false;
        if (n > 1) sieve[1] = false;

        for (ll i = 2; i * i < n; i++) {
            if (sieve[i]) for (ll j = i * i; j < n; j += i) sieve[j] = false;
        }
        ll sumA = 0;
        ll sumB = 0;

        for (ll i = 0; i < n; i++) {
            if (sieve[i])
                sumA += nums[i];
            else
                sumB += nums[i];
        }

        return abs(sumA - sumB);
    }
};