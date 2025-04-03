class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
       int n=nums.size();
       vector<int> pre(n);
       vector<int> suff(n);
       pre[0]=nums[0];
       suff[n-1]=nums[n-1];
       for(int i=1;i<n;i++){
        pre[i]=max(pre[i-1],nums[i]);
       } 
       for(int i=n-2;i>=0;i--){
        suff[i]=max(suff[i+1],nums[i]);
       }
       long long ans=0;
       for(int j=1;j<n-1;j++){
        long long res=(long long)(pre[j-1]-nums[j])*suff[j+1];
        ans=max(ans,res);
       }
       return ans;
    }
};