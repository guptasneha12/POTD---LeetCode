class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int maxi=0;
        int n=nums.size();
        vector<long long> t;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                   t.push_back(static_cast<long long>((nums[i]-nums[j]))*nums[k]);
                }
            }
        }
        long long val=*max_element(t.begin(),t.end());
        return val>0LL?val:0;
    }
};