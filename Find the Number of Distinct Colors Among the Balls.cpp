class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> res;
        unordered_map<int,int> ballcolor;
        unordered_map<int,int> colorcnt;
        for(auto &x:queries){
            int ball=x[0];
            int color=x[1];

            // if ball is already colored the replace past color with new color
            if(ballcolor.find(ball)!=ballcolor.end()){
                int oldcolor=ballcolor[ball];
                if(--colorcnt[oldcolor]==0){
                    colorcnt.erase(oldcolor);
                }
            }

            ballcolor[ball]=color;
            colorcnt[color]++;
            res.push_back(colorcnt.size());
        }
        return res;
    }
};