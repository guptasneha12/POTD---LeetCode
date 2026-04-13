class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mini=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                int x=abs(i-start);
                mini=min(mini,x);
            }
        }
        return mini;
    }
};