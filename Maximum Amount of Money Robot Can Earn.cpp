class Solution {
public:
int n;
int m;
int dp[501][501][3];
int solve(vector<vector<int>>& coins, int i,int j,int neu){
    // base case
    if(i==n-1 && j==m-1){ // end of cell
        // if it is -ve and we have power to neutralise then we can skip that cell coin
        if(coins[i][j]<0 && neu>0){
            return 0;
        }
        // if it is -ve and we have no power to neutralise then we have to take that coin
          return coins[i][j];
    }
    if(i>=n || j>=m) return INT_MIN; // for out of boundary case
    if(dp[i][j][neu]!=INT_MIN) return dp[i][j][neu];
    int take=coins[i][j]+max(solve(coins,i,j+1,neu),solve(coins,i+1,j,neu));
    int skip=INT_MIN;
    if(coins[i][j]<0 && neu>0){
        int skipright=solve(coins,i,j+1,neu-1);
        int skipdown=solve(coins,i+1,j,neu-1);
        skip=max(skipright,skipdown);
    }
    return dp[i][j][neu]=max(take,skip);
}
    int maximumAmount(vector<vector<int>>& coins) {
        n=coins.size();
        m=coins[0].size();
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k]=INT_MIN; // because maximum value can be calculated
                }
            }
        }
        return solve(coins,0,0,2);
        
    }
};