class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        for(int i=0;i<n;i++){
            int r=(startIndex+i)%n;
            int l=(startIndex-i+n)%n;
            if(words[r]==target || words[l]==target){
                return i; 
            }
        }
        return -1;
    }
};