#include <vector>
using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // If Alice never needs to draw OR she can never go over n
        if (k == 0 || n >= k + maxPts) return 1.0;

        vector<double> prob(n + 1, 0.0);
        prob[0] = 1.0;

        double windowSum = 1.0; // running sum of last maxPts values
        double ans = 0.0;

        for (int i = 1; i <= n; i++) {
            prob[i] = windowSum / maxPts;

            if (i < k) {
                windowSum += prob[i];   // still in game
            } else {
                ans += prob[i];         // game ends at i
            }

            if (i - maxPts >= 0) {
                windowSum -= prob[i - maxPts]; // slide window
            }
        }

        return ans;
    }
};
