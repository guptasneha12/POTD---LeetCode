class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int prod=nums[i]*nums[j];
                mp[prod]++;
            }
        }

        int res=0;
        for(auto& [ele,cnt]:mp){
            if(cnt>1){
                res+=(cnt*(cnt-1))/2;
            }
        }
        return res*8;
    }
};