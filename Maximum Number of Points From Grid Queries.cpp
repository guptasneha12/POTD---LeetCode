class Solution {
public:
 vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size();
        int m=grid[0].size();
        int q=queries.size();
        vector<int> ans(q,0);
        vector<pair<int,int>> sortedq;
        for(int i=0;i<q;i++){
            sortedq.push_back({queries[i],i});
        }
        sort(sortedq.begin(),sortedq.end());

        // min heap
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        pq.push({grid[0][0],0,0});
        vis[0][0]=true;
        int points=0;
        for(int i=0;i<q;i++){
            int val=sortedq[i].first;
            int idx=sortedq[i].second;
            while(!pq.empty() && pq.top()[0]<val){
              int i=pq.top()[1];
              int j=pq.top()[2];
              pq.pop();
              points++;
              for(auto& dir:directions){
                int ni=i+dir[0];
                int nj=j+dir[1];
                if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj]){
                    pq.push({grid[ni][nj],ni,nj});
                    vis[ni][nj]=true;
                }
              }
            }
            ans[idx]=points;
        }
        return ans;
    }
};