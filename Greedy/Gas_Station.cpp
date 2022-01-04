int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    int start = -1;
    int sum = 0;
    for(int i=0; i<gas.size(); i++) {
        if (gas[i] >= cost[i]) {
            start = i;
            break;
        }
    }
    if (start == -1) return start;
    for(int i=start; i<gas.size();) {
        sum += gas[i] - cost[i];
        if (sum < 0) {
            i++;
            while(i < gas.size()) {
                if (gas[i] >= cost[i]) {
                    start = i;
                    sum = 0;
                    break;
                }
                i++;
            }
        }
        else i++;
    }
    if (sum < 0) return -1;
    for(int i=0; i<start; i++) {
        sum += gas[i]-cost[i];
        if (sum < 0) return -1;
    }
    return start;
}