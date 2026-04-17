class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
          int rev=reverse(nums[i]);
          // current number is present in map or not
          if(mp.count(nums[i])){
           ans=min(ans,i-mp[nums[i]]);
          }
          // update the index of the revresed num
          mp[rev]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};