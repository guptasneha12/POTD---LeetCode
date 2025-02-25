class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD=1e9+7;
        int n=arr.size();
        
        int oddcount=0,evencount=1;
        int currsum=0,res=0;
        for(auto it:arr){
            currsum+=it;
            if(currsum%2==0){
                res=(res+oddcount)%MOD;
                evencount++;
            }
            else{
                res=(res+evencount)%MOD;
                oddcount++;
            }
        }
       
         return res;

    }
};