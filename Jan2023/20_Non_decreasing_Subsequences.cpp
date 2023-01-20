class Solution {
public:
    vector<vector<int>> v;
    void makeSequence(vector<int>& nums,vector<int> curr,int s){
        if(s>=nums.size()){
            if(curr.size()>=2){
                v.push_back(curr);
            }
            return;
        }
        if(curr.size()==0 || curr.back()<=nums[s]){
                curr.push_back(nums[s]);
                makeSequence(nums,curr,s+1);
                curr.pop_back();
        }
        makeSequence(nums,curr,s+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        makeSequence(nums,{},0);
        map<vector<int>,int> mp;
        for(auto i:v){
            if(mp.count(i)==0){
                mp[i]=1;
            }
        }
        v.clear();
        for(auto [i,j]:mp){
            v.push_back(i);
        }
        return v;
    }
};


