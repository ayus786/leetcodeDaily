class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int x_start=points[0][0],x_end=points[0][1],arrow=1;
        for(int i=1; i<points.size(); i++){
            if(points[i][1]<=x_end || points[i][0]<=x_end){
                x_start=max(x_start,points[i][0]);
                x_end=min(x_end,points[i][1]);
            }
            else{
                x_start=points[i][0];
                x_end=points[i][1];
                arrow++;
            }
        }
        return arrow;
    }
};
