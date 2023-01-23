class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        map<int,pair<int,int>> mp;
        for(auto i:trust){
            int a=i[0];
            int b=i[1];
            if(mp.count(a)) mp[a].first+=1;
            else mp[a]={1,0};
            if(mp.count(b)) mp[b].second+=1;
            else mp[b]={0,1};
            
        }
        for(auto [i,x]:mp){
            if(x.first==0 && x.second==n-1) return i;
        }
        return -1;
    }
};
