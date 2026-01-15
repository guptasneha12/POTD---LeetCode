class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // first sort to find max consecutive subarray
        int a=hBars.size();
        int b=vBars.size();
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int maxconshbars=1;
        int maxconsvbars=1;
        int currconshbars=1;
        // horizontal bar sequence
        for(int i=1;i<a;i++){
            if(hBars[i]-hBars[i-1]==1){
                currconshbars++;
            }
            else currconshbars=1; //restart
            maxconshbars=max(maxconshbars,currconshbars);
        }

        // vertical bar sequence
        int currconsvbars=1;
        for(int i=1;i<b;i++){
            if(vBars[i]-vBars[i-1]==1){
                currconsvbars++;
            }
            else currconsvbars=1; // restart
            maxconsvbars=max(maxconsvbars,currconsvbars);
        }
        int side=1;
        side=min(maxconshbars,maxconsvbars)+1;
        return side*side;
    }
};