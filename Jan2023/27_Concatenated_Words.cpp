class Solution {
public:
    bool conCat(string s,unordered_map<string,int>& mp,int st=0,int k=0){
        if(st==s.size() && k>1){
            return true;
        }
        string ss="";
        bool ans=false;
        for(int i=st; i<s.size(); i++){
            ss+=s[i];
            if(mp[ss]){
                ans|=conCat(s,mp,i+1,k+1);
            }
        }
        return ans;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto i:words){
            mp[i]=1;
        }
        vector<string> v;
        for(auto i:words){
            if(conCat(i,mp)){
                v.push_back(i);
            }
        }
        return v;
    }
};

/*

catsdogcats
cat -> sdogcats
cats->

*/
