class Solution {
public:
    string smallestNumber(string pattern) {
        string res;
        stack<char> st{{'1'}};
        for(char c:pattern){
            char maxi=st.top();
            if(c=='I'){
              while(!st.empty()){
             maxi=max(maxi,st.top());
             res+=st.top();
             st.pop();
              }
            }
            st.push(maxi+1);
        }

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};