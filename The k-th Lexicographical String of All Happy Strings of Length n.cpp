class Solution {
public:
void solve(int n,string &res,string &curr,int &cnt,int k){
    if(curr.size()==n){
        cnt++;
        if(cnt==k){
            res=curr;
            return;
        }
        return;
    }
  
  for(char ch='a';ch<='c';ch++){
    if(!curr.empty() && curr.back()==ch) continue;
    // do
    curr.push_back(ch);
   // explore
   solve(n,res,curr,cnt,k);
   // undo
   if(!res.empty()) return;
   curr.pop_back();
  }


}
    string getHappyString(int n, int k) {
        string res="";
        string curr="";
        int cnt=0;
        solve(n,res,curr,cnt,k);
        return res;
    }
};