class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        long long res=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            // lower bound gives the idx of first element which is not less than lower-nums[i];
            int idx=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            int x=idx-i-1;

            // upper bound gives the idx of first element which is greater than upper-nums[i];
            idx=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
            int y=idx-i-1;
            res+=(y-x);
        }
        return res;
    }
};