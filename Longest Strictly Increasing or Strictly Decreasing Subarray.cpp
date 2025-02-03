class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=1,in=1,de=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                in+=1;
                de=1;
            }else if(nums[i]<nums[i-1]){
                de+=1;
                in=1;
            }else{
                in=1;
                de=1;
            }
            maxi=max(maxi,max(in,de));
        }
        return maxi;
    }
};