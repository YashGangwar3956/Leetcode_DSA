class Solution {
public:
    int n;
    vector<int> demand;
    map<long long, pair<int, int>> memo;
    long long encode (int i, int fuel0, int fuel1, int busy0, int busy1) {
        long long a = (i * 51 + fuel0);
        long long b = (a * 51 + fuel1);
        long long c = (b * 21 + busy0);
        long long d = (c * 21 + busy1);
        return d;
    }
    pair<int, int> solve (int i, int fuel0, int fuel1, int busy0, int busy1) {
        if (i == n) {
            return {0, 0};
        }
        int curr_demand = demand[i];
        if (curr_demand > max(fuel0, fuel1)) {
            return {0, 0};
        }
        long long key = encode(i, fuel0, fuel1, busy0, busy1);
        if (memo.count(key)) {
            return memo[key];
        }
        int maxServedCars = 0, maxWaitTime = INT_MAX;
        if (curr_demand <= fuel0) {
            int currWaitTime = busy0;
            int newBusy0 = curr_demand;
            int newBusy1 = max(0, busy1 - busy0);
            auto [nextServedCars, nextWaitTime] = solve(i + 1, fuel0 - curr_demand, fuel1, newBusy0, newBusy1);
            nextServedCars += 1;
            nextWaitTime = max(nextWaitTime, currWaitTime);
            if (nextServedCars > maxServedCars) {
                maxServedCars = nextServedCars;
                maxWaitTime = nextWaitTime;
            } else if (nextServedCars == maxServedCars && nextWaitTime < maxWaitTime) {
                maxWaitTime = nextWaitTime;
            }
        }   
        if (curr_demand <= fuel1) {
            int currWaitTime = busy1;
            int newBusy1 = curr_demand;
            int newBusy0 = max(0, busy0 - busy1);
            auto [nextServedCars, nextWaitTime] = solve(i + 1, fuel0, fuel1 - curr_demand, newBusy0, newBusy1);
            nextServedCars += 1;
            nextWaitTime = max(nextWaitTime, currWaitTime);
            if (nextServedCars > maxServedCars) {
                maxServedCars = nextServedCars;
                maxWaitTime = nextWaitTime;
            } else if (nextServedCars == maxServedCars && nextWaitTime < maxWaitTime) {
                maxWaitTime = nextWaitTime;
            }
        }
        return memo[key] = {maxServedCars, maxWaitTime};
    }
    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
        this -> demand = demand;
        n = demand.size();
        auto [maxCars, maxWait] = solve(0, fuel[0], fuel[1], 0, 0);
        if (maxCars == 0) {
            return -1;
        }
        return maxWait;
    }
};