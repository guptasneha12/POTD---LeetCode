class Solution {
public:
int M=1e9+7;
vector<vector<int>> dp;
string state[12]={"RGY","RYG","RGR","RYR","GYR","GRY","GRG","GYG","YRG","YGR","YRY","YGY"};
int solve(int n,int prev){
    // base case
    if(n==0) return 1; // means there is only 1 way
    if(dp[n][prev]!=-1) return dp[n][prev];
    int res=0;
    string last=state[prev];
    for(int curr=0;curr<12;curr++){
        if(curr==prev) continue;
        string currpat=state[curr];
        bool conflict=false;
        // do match with prev choosen color
        for(int col=0;col<3;col++){
            if(currpat[col]==last[col]){
                conflict=true;
                break;
            }
        }
        if(!conflict){
            res=(res+solve(n-1,curr))%M;
        }
    }
return dp[n][prev]=res;
}
    int numOfWays(int n) {
     dp.resize(n+1,vector<int>(12,-1));
        int res=0;
        for(int i=0;i<12;i++){
            res=(res+solve(n-1,i))%M;
        }
        return res;
    }
};