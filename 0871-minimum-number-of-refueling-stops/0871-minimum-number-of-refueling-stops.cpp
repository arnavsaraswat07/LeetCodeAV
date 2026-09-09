class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        priority_queue<int> pq; // max heap

        int fuel = startFuel;
        int stops = 0;
        int prev = 0;

        for (int i = 0; i <= stations.size(); i++) {

            // If i == n, destination is the target
            int pos = (i == stations.size()) ? target : stations[i][0];

            // Fuel needed to reach this position
            int distance = pos - prev;
            fuel -= distance;

            // We don't have enough fuel to reach this position
            while (fuel < 0 && !pq.empty()) {
                fuel += pq.top();
                pq.pop();
                stops++;
            }

            // Still can't reach it
            if (fuel < 0) {
                return -1;
            }

            // If this is a station, save its fuel for later
            if (i < stations.size()) {
                pq.push(stations[i][1]);
            }

            prev = pos;
        }

        return stops;
    }
};