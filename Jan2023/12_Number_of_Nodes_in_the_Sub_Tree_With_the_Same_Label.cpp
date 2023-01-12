class Solution {
public:
     vector<int> countNode(int node,int parent,vector<int> adj[],string& labels,vector<int>& values){
        vector<int> chr(26,0);
         chr[labels[node]-'a']=1;
        for(auto child:adj[node]){
            if(child==parent) continue;
            vector<int> childCount = countNode(child,node,adj,labels,values);
            for(int i=0; i<26; i++){
                chr[i]+=childCount[i];
            }
        }
         values[node]=chr[labels[node]-'a'];
        return chr;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> adj[n],values(n,0);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        countNode(0,-1,adj,labels,values);
        return values;
    }
};
