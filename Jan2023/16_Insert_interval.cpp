class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newIn) {
        int n=in.size();
        vector<vector<int>> v;
        int i=0;
        while(i<n && in[i][1]<newIn[0]){
            v.push_back(in[i]);
            i++;
        }
        while(i<n && in[i][0]<=newIn[1]){
            newIn[0] = min(newIn[0],in[i][0]);
            newIn[1] = max(newIn[1],in[i][1]);
            i++;
        }
        v.push_back(newIn);
        while(i<n){
            v.push_back(in[i]);
            i++;
        }
        return v;
    }
};
