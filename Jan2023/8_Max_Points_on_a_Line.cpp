// BRUTE FORCE : CHECK ALL THE POSIBILITIES
class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int n=p.size();
        if(n<=2) return n;
        int maxi=2;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int total = 2;
                for(int k=j+1; k<n; k++){
                    // if(i!=k && k!=j) 
                    if((p[i][0]-p[j][0])*(p[j][1]-p[k][1])==(p[i][1]-p[j][1])*(p[j][0]-p[k][0])) total+=1;
                }
                maxi=max(maxi,total);
            }
        }
        return maxi;
    }
};

// optimized
#define INF 1000000
class Solution {
public:
    int maxPoints(vector<vector<int>>& pt) {
        int ans=1; 
        int n=pt.size();
        for(int i=0;i<n-1;i++){
            map<double,int> mp;
            for(int j=i+1;j<n;j++){
                double x = (double)(pt[j][1]-pt[i][1])/(double)(pt[j][0]-pt[i][0]);
                if((pt[j][0]-pt[i][0])==0 )
                    mp[INF]++; 
                else
                    mp[x]++;
            }
            int temp = 0;
            for(auto it:mp)
                temp = max(temp, it.second+1);
            ans = max(temp, ans);
        }
        return ans;
    }
};
