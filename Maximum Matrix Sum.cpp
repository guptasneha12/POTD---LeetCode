class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int cnt = 0; // count of -ve no.
        int smallestnegno = INT_MAX;
        for (int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0) cnt++;
                smallestnegno=min(smallestnegno,abs(matrix[i][j]));
            }
        }
        if(cnt%2==0){
            return sum;
        }
        return sum-2*smallestnegno;
    }
};