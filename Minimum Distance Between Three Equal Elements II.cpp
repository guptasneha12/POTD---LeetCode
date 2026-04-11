class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto &it:mp){
            vector<int> &temp=it.second;
            int m=temp.size();
            if(m>=3){
             for(int i=0;i<m-2;i++){
                int a=temp[i];
                int b=temp[i+1];
                int c=temp[i+2];
                int x=2*(c-a);
                ans=min(ans,x);
             }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};