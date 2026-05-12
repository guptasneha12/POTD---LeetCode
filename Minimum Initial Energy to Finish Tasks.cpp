class Solution {
public:
bool ispossible(vector<vector<int>>& tasks,int mid){
   for(auto &t:tasks){
    int actual=t[0];
    int mini=t[1];
    if(mini>mid){
        return false;
    }
    mid-=actual;
   }
    return true;
}
    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
        int l=0;
        int r=1e9;
        int ans=INT_MAX;
    
        auto comp=[](auto &task1, auto &task2){
            int d1=task1[1]-task1[0];
            int d2=task2[1]-task2[0];
            return d1>d2;
        };

        sort(tasks.begin(),tasks.end(),comp);
        // binary search
        while(l<=r){
        int mid=l+(r-l)/2;
        if(ispossible(tasks,mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
        }
return ans;
    }
};