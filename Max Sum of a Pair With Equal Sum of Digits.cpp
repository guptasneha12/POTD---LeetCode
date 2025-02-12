class Solution {
public:
int findsum(int n){
    int sum=0;
    while(n>0){
        sum+=(n%10);
        n/=10;
    }
    return sum;
}



    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,priority_queue<int>> mp;
  
        for(auto& it:nums){
           int sum=findsum(it);
           mp[sum].push(it);
        }

        int maxi=-1;
        for(auto& it:mp){
            if(it.second.size()>1){
             int sum=it.second.top();
             it.second.pop();
             sum+=it.second.top();
             maxi=max(maxi,sum);
            }
        }
return maxi;
    }
};