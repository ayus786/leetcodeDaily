class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<vector<int>> v=board;
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n; j++){
                swap(v[i][j],v[n-i-1][j]);
            }
        }
        for(int i=0; i<n; i++){
            if(i%2){
                for(int j=0; j<n/2; j++){
                    swap(v[i][j],v[i][n-j-1]);
                }
            }
        }
        queue<int> q;
        q.push(1);
        int step=0;
        while(q.size()){
            int size = q.size();
            step++;
            for(int i=0; i<size; i++){
                int cur = q.front(); q.pop();
                for(int j = 1; j <=6; ++j) {
                    int y = cur+j;
                    if (y > n*n) continue;
                    int row=(y-1)/n;
                    int col=(y-1)%n;
                    if(v[row][col]==0) continue;
                    if(v[row][col]>0){
                        y=v[row][col];
                    }
                    if(y==n*n) return step;
                    v[row][col]=0;
                    q.push(y);
                }
                cout<<endl;
            }
            cout<<endl;
        }
        return -1;
    }
};
/*
-1 6 2 8 
-1 -1 10 -1 
2 13 15 -1 
-1 2 1 -1 
*/
