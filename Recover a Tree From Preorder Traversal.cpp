class Solution {
public:

TreeNode* solve(string &s,int &i, int depth){
    int n=s.size();
// base caes
if(i>=n) return NULL;
int j=i;

while(j<n && s[j]=='-'){
j++;
}
int dash=j-i;
if(dash!=depth) return NULL;

// move i to j
i+=dash;
int num=0;
while(i<n && isdigit(s[i])){
    num=(num*10)+(s[i]-'0');
    i++;
}

TreeNode* root=new TreeNode(num);
root->left=solve(s,i,depth+1);
root->right=solve(s,i,depth+1);

return root;

}

    TreeNode* recoverFromPreorder(string s) {
        int n=s.size();
        int depth=0;
        int i=0;  // start traversing from 0 index of string
        return solve(s,i,depth);
    }
};