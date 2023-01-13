// concept of 11 jan,12 jan and this one, all are of same concept. Like we have to count the results from leaf till a child and child will give the result. All are like bottom-up method.
// This one is little bit like diameter of a tree, where our first long is like longest from one side and other is second longest and then we will change its value according to our child node result which we store in longestPathFromChild

// We will return the longestPath we get from that node and it will store as a longest path from that till from leaf

class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, string& s, int& maxPath) {
        int firstLong=0,secondLong=0;
        for(auto child:adj[node]){
            int longestPathFromChild = dfs(child,adj,s,maxPath);
            if(s[child]==s[node]) continue;
            if(longestPathFromChild>firstLong){
                secondLong = firstLong;
                firstLong = longestPathFromChild;
            }
            else if(longestPathFromChild>secondLong){
                secondLong = longestPathFromChild;
            }
        }
        maxPath = max(maxPath,secondLong+firstLong+1);
        return firstLong+1;
        
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        int maxPath = 1;
        dfs(0, adj, s, maxPath);

        return maxPath;
    }
};
