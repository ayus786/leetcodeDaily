class DSU{
private:
    vector<int> parent,rank;
public:
    DSU(int size){
        parent.resize(size);
        rank.resize(size,0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    int find(int x){
        if(x!=parent[x]){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void uni(int x,int y){
        int x_par = find(x);
        int y_par = find(y);
        if(x_par==y_par) return;
        else if(rank[x_par]<rank[y_par]){
            parent[x_par]=y_par;
        }
        else if(rank[x_par]>rank[y_par]){
            parent[y_par]=x_par;
        }
        else{
            parent[x_par]=y_par;
            rank[y_par]++;
        }
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[vals[i]].push_back(i);
        }
        
        DSU dsu(n);
        int goodPaths = 0;
        for (auto& [value, nodes] : mp) {
            for (int node : nodes) {
                for (int neighbor : adj[node]) {
                    
                    if (vals[node] >= vals[neighbor]) {
                        dsu.uni(node, neighbor);
                    }
                }
            }
            
            unordered_map<int, int> group;
            
            for (int u : nodes) {
                group[dsu.find(u)]++;
            }
            for (auto& [s, size] : group) {
                goodPaths += (size * (size + 1) / 2);
            }
        }
        
        return goodPaths;
    }
};
