class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        int partlen=part.size();
        for(char c:s){
            ans.push_back(c);
           if(ans.size()>=partlen && ans.substr(ans.size()-partlen)==part){
            ans.erase(ans.size()-partlen,partlen);
           }
        }
        return ans;
    }
};