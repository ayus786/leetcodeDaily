// Iterative
class Solution {
public:
    void makeIp(string s1,string s2,string s3,string s4,vector<string>& ss){
        long MAX = 255,MIN=0;
        long val1 = stoll(s1),val2 = stoll(s2),val3 = stoll(s3),val4 = stoll(s4);
        if(val1<=MAX && val2<=MAX && val3<=MAX && val4<=MAX){
            if(!((s1.size()>1 && s1[0]=='0') || (s2.size()>1 && s2[0]=='0') || (s3.size()>1 && s3[0]=='0') || (s4.size()>1 && s4[0]=='0'))){
                ss.push_back(s1+'.'+s2+'.'+s3+'.'+s4);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ss;
        if(s.size()<4 || s.size()>12) return {};
        int n=s.size();
        string s1="",s2="",s3="",s4="";
        for(int i=0; i<n-3; i++){
            if(i>=3) continue;
            s1 = s.substr(0,i+1);
            for(int j=i+1; j<n-2; j++){
                if(j-i>3) continue;
                s2 = s.substr(i+1,j-i);
                int y = -1;
                for(int k=j+1; k<n-1; k++){
                    if(j-j>6) break;
                    if(k-j>3){
                        s4 = s.substr(y+1);
                    }
                    else{
                        s3 = s.substr(j+1,k-j);
                        s4 = s.substr(k+1);
                        y=k;
                    }
                    makeIp(s1,s2,s3,s4,ss);
                }
            }
            
        }
        map<string,int> mp;
        for(auto i:ss){
            if(mp.count(i)) continue;
            mp[i]=1;
        }
        ss.clear();
        for(auto [i,j]:mp){
            ss.push_back(i);
        }
        return ss;
    }
};

/*

0-255
25525511135
25525511.1.3.5

*/
