
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxHeap;  
        int n = stations.size();
        int i = 0, stops = 0;
        long long fuel = startFuel;

        while (fuel < target) {
            while (i < n && stations[i][0] <= fuel) {
                maxHeap.push(stations[i][1]);
                i++;
            }

            if (maxHeap.empty()) return -1;

            fuel += maxHeap.top();
            maxHeap.pop();
            stops++;
        }

        return stops;
    }
};
