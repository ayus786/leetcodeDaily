class Solution {
public:
    vector<vector<string>> v;
    bool isPallindrome(string s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void makePartition(string s,int pos,vector<string> vv){
        if(pos==s.size()){
            v.push_back(vv);
            return;
        }
        string ss="";
        for(int i=pos; i<s.size(); i++){
            ss+=s[i];
            if(isPallindrome(ss)){
                vv.push_back(ss);
                makePartition(s,i+1,vv);
                vv.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> vv;
        makePartition(s,0,vv);
        return v;
    }
};
