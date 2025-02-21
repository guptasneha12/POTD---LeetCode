class FindElements {
public:
unordered_map<int,bool> mp;

void solve(TreeNode* root){
    if(root->left){
        root->left->val=2*root->val+1;
        mp[root->left->val]=true;
        solve(root->left);
    }
    if(root->right){
        root->right->val=2*root->val+2;
        mp[root->right->val]=true;
        solve(root->right);
    }
}


    FindElements(TreeNode* root) {
        root->val=0;
        mp[0]=true;
        solve(root);
    }
    
    bool find(int target) {
       return mp[target]; 
    }
};