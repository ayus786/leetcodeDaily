class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        unordered_map<string,char> mpp;
        vector<string> ss;
        string sx="";
        for(auto i:s){
            if(i==' '){
                ss.push_back(sx);
                sx="";
            }
            else sx+=i;
        }
        ss.push_back(sx);
        if(ss.size()!=pattern.size()) return false;
        for(int i=0; i<pattern.size(); i++){
            if((mp.count(pattern[i])>0 && mp[pattern[i]]!=ss[i]) || mpp.count(ss[i])>0 && mpp[ss[i]]!=pattern[i]) return false;
            mp[pattern[i]]=ss[i];
            mpp[ss[i]]=pattern[i];
        }
        return true;
    }
};
