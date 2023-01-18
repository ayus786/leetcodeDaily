class Solution {
public:
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int cur_min=0,cur_max=0,sum=0,maxi=nums[0],mini=nums[0];
        for(auto i:nums){
            cur_max = max(cur_max,0) + i;
            cur_min = min(cur_min,0) + i;
            maxi=max(maxi,cur_max);
            mini=min(mini,cur_min);
            sum+=i;
        }
        if(sum==mini) return maxi;
        else{
            return max(maxi,sum-mini);
        }
        return 0;
    }
};
/*


*/
