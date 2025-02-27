class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        if(n<=2) return 0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int curr=arr[j];
                int prev=arr[i];
                int len=2;
                // next fibonacci number is found
                while(mp.find(prev+curr)!=mp.end()){
                 len++;
                 maxi=max(maxi,len);
                 int x=curr;
                 curr=curr+prev;
                 prev=x;
                }

            }
        }
        return (maxi>2)?maxi:0;
    }
};