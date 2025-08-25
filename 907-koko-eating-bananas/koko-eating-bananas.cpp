class Solution {
public:
    // Helper function: checks if Koko can eat all bananas
    // at speed k within h hours
    bool canFinish(const vector<int>& piles, int h, int k) {
        long long hours = 0;  // use long long to avoid overflow
        for (int pile : piles) {
            // Time to eat this pile = ceil(pile / k)
            hours += pile / k;
            if (pile % k != 0) hours++;  // add 1 if not divisible exactly

            // Optimization: stop early if already exceeding h
            if (hours > h) return false;
        }
        return hours <= h;
    }

    // Main function: binary search for minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;  // lowest possible speed
        int right = *max_element(piles.begin(), piles.end()); // highest possible speed
        int ans = right; // worst case: eat max pile in 1 hour

        while (left <= right) {
            int mid = left + (right - left) / 2;  // safe mid calculation

            if (canFinish(piles, h, mid)) {
                // If Koko can finish with this speed,
                // try a smaller speed
                ans = mid;
                right = mid - 1;
            } else {
                // Otherwise, need to eat faster
                left = mid + 1;
            }
        }
        return ans;
    }
};