class Solution {
public:
    bool rotateString(string s, string goal) {
        int n =s.size();
        int l=goal.size();
        return (n==l) && (s+s).find(goal)!=-1;
    }
};