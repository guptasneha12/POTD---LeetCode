class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int maxside = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // top right coordinates
                int toprightx = min(topRight[i][0], topRight[j][0]);
                int toprighty = min(topRight[i][1], topRight[j][1]);
                // bottom left coordinates
                int bottomleftx = max(bottomLeft[i][0], bottomLeft[j][0]);
                int bottomlefty = max(bottomLeft[i][1], bottomLeft[j][1]);
                // width
                int width = toprightx - bottomleftx;
                // height
                int height = toprighty - bottomlefty;
                int side = min(width, height);
                maxside = max(maxside, side);
            }
        }
        return 1LL * maxside*maxside;
    }
};