class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod=1e9+7;
        for(auto &a:queries){
            for(int i=a[0];i<=a[1];i+=a[2]){
                long long k=1LL*nums[i]*a[3];
                nums[i]=(int)(k%mod);
            }
        }
        int ans=0;
        for(int x:nums) ans^=x;
        return ans;
    }
};