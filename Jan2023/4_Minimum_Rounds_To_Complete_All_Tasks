class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto i:tasks){
            mp[i]++;
        }
        int sum=0;
        for(auto i:mp){
            if(i.second<2){
                return -1;
            }
            else{
                if(i.second%3==0){
                    sum+=(i.second/3);
                }
                else sum+=(i.second/3)+1;
            }
        }
        return sum;
    }
};
