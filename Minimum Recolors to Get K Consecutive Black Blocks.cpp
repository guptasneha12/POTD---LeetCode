class Solution {
public:
    int minimumRecolors(string blocks, int k) {
      // use sliding window approach
      int n=blocks.size();
      int res=INT_MAX;
      int bcnt=0;
      for(int i=0;i<n;i++){
        // if window size os more than 7
        if(i-k>=0 && blocks[i-k]=='B') bcnt--;
        if(blocks[i]=='B') bcnt++;
        res=min(res,k-bcnt);
      }
      return res;
    }
};