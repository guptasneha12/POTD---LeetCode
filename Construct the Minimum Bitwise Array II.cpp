class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==2){
                res.push_back(-1);
                continue;
            }
            bool found=false;
            for(int j=1;j<32;j++){
              if((nums[i]&(1<<j))>0){
                continue; // if it is a set bit
              }
              // unset bit found
              int prev=j-1;
              // set unset bit to 0
              int x=(nums[i]^(1<<(j-1)));
              res.push_back(x);
              found=true;
              break;
            }
            if(found==false){
                res.push_back(-1);
            }
        }
        return res;
    }
};