class Solution {
public:
    int countDays(int days, vector<vector<int>>& arr) {
        // use overlapping subproblem
        sort(arr.begin(),arr.end());
        vector<vector<int>> merge;
        // merging of overlapping intervals
        for(auto it:arr){
            if(merge.empty() || it[0]>merge.back()[1]){
                merge.push_back(it);
            }else{
                merge.back()[1]=max(merge.back()[1],it[1]);
            }
        }
  // count the free days
  int cnt=0;
  for(auto it:merge){
   cnt+=(it[1]-it[0]+1);
  }
  return days-cnt;
    }
};