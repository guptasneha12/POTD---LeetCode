class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // find the good pair instead and subtract it from total pairs
        int n=nums.size();
        long long s=n;
        unordered_map<int,long long> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]-i]++;
        }
        long long cnt=0;
        for(auto& [ele,val]:mp){
            cnt+=(val*(val-1))/2;
        }
        return (s*(s-1))/2-cnt;
    }
};