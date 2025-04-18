class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string res="";
        string sol=countAndSay(n-1);
        for(int i=0;i<sol.size();i++){
            char ch=sol[i];
            int  cnt=1;
            while(i<sol.size()-1 && sol[i]==sol[i+1]){
                cnt++;
                i++;
            }
            res+=to_string(cnt)+string(1,ch);
        }
        return res;
    }
};