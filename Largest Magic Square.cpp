class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> prerowsum(row,vector<int>(col));
        vector<vector<int>> precolsum(row,vector<int>(col));
        // cummulative prefix row sum
        for(int i=0;i<row;i++){
            prerowsum[i][0]=grid[i][0];
            for(int j=1;j<col;j++){
             prerowsum[i][j]=prerowsum[i][j-1]+grid[i][j];
            }
        }
        //cummulativr prefix column sum
        for(int j=0;j<col;j++){
            precolsum[0][j]=grid[0][j];
            for(int i=1;i<row;i++){
                precolsum[i][j]=precolsum[i-1][j]+grid[i][j];
            }
        }
        // start with the maximum side of square
        for(int side=min(row,col);side>=2;side--){
            // check for magical square
            for(int i=0;i+side-1<row;i++){
                for(int j=0;j+side-1<col;j++){
                    int targetsum=prerowsum[i][j+side-1]-(j>0 ? prerowsum[i][j-1] : 0);
                    bool allsame=true;
                    // check for rows
                    for(int r=i+1;r<i+side;r++){
                     int rowsum=prerowsum[r][j+side-1]-(j>0 ? prerowsum[r][j-1] : 0);
                     if(rowsum!=targetsum){
                        allsame=false;
                        break;
                     }
                    }
                    if(allsame==false) continue;
                    // check for columns
                    for(int c=j;c<j+side;c++){
                        int colsum=precolsum[i+side-1][c]-(i>0? precolsum[i-1][c] : 0);
                        if(colsum!=targetsum){
                            allsame=false;
                            break;
                        }
                    }
                    if(allsame == false) continue;

                    // check for diagonal and anti diagonal
                    int diag=0,antidiag=0;
                    for(int k=0;k<side;k++){
                        diag+=grid[i+k][j+k];
                        antidiag+=grid[i+k][j+side-1-k];
                    }
                    if(diag==targetsum && antidiag==targetsum) return side;
                }
            }
        }
        return 1;
    }
};