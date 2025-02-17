class Solution {
public:
int solve(string tiles,vector<bool> &used){
    int cnt=0;
    for(int i=0;i<tiles.size();i++){
        if(used[i] || (i>0 && tiles[i]==tiles[i-1] && !used[i-1])) continue;
        used[i]=true;
        cnt+=1+solve(tiles,used);
        used[i]=false;
    }
    return cnt;
}
    int numTilePossibilities(string tiles) {
        int n=tiles.size();
        sort(tiles.begin(),tiles.end());
        vector<bool> used(n,false);
        return solve(tiles,used);
    }

};