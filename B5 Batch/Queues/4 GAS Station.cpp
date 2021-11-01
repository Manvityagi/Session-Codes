class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //check if solution exists
        int total_gas = 0, total_cost = 0;
        for (int i = 0; i < gas.size(); i++) {
            total_gas += gas[i];
            total_cost += cost[i];
        }
        if (total_gas < total_cost) {
            return -1;
        }
   
        // find out starting point
        int total_current_gas = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            total_current_gas += gas[i] - cost[i];
            if (total_current_gas < 0) {
                start = i + 1;
                total_current_gas = 0;
            }
        }
        return start;
    }
};