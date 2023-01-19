class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        mp[0]=1;
        int sum=0;
        int res=0;
        for(auto i: nums){
            sum=(((sum+i%k)+k)%k);
            res+=(mp[sum]);
            mp[sum%k]++;
        }
        return res;
    }
};
