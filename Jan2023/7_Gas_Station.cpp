class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0;
        int sum = 0;
        int s = 0;
        
        for(int i = 0; i < n; i++){
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if(sum < 0){
                sum = 0;
                s = i + 1;
            }
        }
        if(total<0) return -1;
        return s;
    }
};
