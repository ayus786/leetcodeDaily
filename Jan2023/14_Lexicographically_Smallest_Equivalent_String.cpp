class Solution {
public:
    char find_set(char c,map<char,char>& parent)
    {
        if(parent[c]==c) return c;
        else 
        {
            return parent[c]=find_set(parent[c],parent);
        }
    }

    void union_set(map<char,char>& parent,char c1,char c2){
        int p1=find_set(c1,parent);
        int p2=find_set(c2,parent);

        if(p1<p2)
        {
            parent[p2]=p1;
        }

        else{
            parent[p1]=p2;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map<char,char> parent;
        for(int i=0;i<26;i++)
        {
            parent[char(i+'a')]= char(i+'a');
        }

        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            union_set(parent,s1[i],s2[i]);
        }

        int l=baseStr.size();
        string req="";
        for(int i=0;i<l;i++)
        {
            req+=find_set(baseStr[i],parent);
        }

        return req;

    }
};
