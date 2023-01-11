/*
As question say that its a tree so there will be no cycle. So there is no need of visited array.
So we will initally make a graph adj from given binary tree.
Then we will apply dfs with current parent -1 and with node 0, Initally we will have time=0. Then we will iterate through our child of parent.

In that loop we will check for if the child is equal to parent like
0->1 and 1->0 it will cause infinte loop.

So after that we will take the time we get from children of that parent
and after that we will check that if we have some timefromChild or child is having an apple then it will take 2 unit of time from its parent.
So we will add 2 unit time in out total time and we will return time in the end.
*/
class Solution {
public:
    int findTime(int node,int parent,vector<int> adj[],vector<bool>& hasApple){
        int time=0;
        for(auto child:adj[node]){
            if(child==parent) continue;
            int timeFromChild = findTime(child,node,adj,hasApple);
            
            if(timeFromChild>0 || hasApple[child]){
                time+=timeFromChild+2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return findTime(0,-1,adj,hasApple);
    }
};
