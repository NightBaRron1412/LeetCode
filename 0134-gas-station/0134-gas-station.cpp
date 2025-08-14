class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        size_t n = gas.size();

        for (int i = 0; i < n; i++)
        {
            total_gas += gas[i];
            total_cost += cost[i];
        }

        if (total_cost > total_gas)
        {
            return -1;
        }

        int tank = 0;
        int start = 0;

        for (int i = 0; i < n; i++)
        {
            tank += gas[i] - cost[i];
            if (tank < 0)
            {
                start = i + 1;
                tank = 0;
            }
            
        }

        return start;

    }
};