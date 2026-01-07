/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long M=1e9+7;
    long ts=0,maxi=0;
    int totalsum(TreeNode* root){
        if(root==NULL) return 0;
        int leftsum=totalsum(root->left);
        int rightsum=totalsum(root->right);
        int sum=root->val+leftsum+rightsum;
        maxi=max(maxi,(ts-sum)*sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        if(!root) return 0;
        ts=totalsum(root);
        totalsum(root);
        return maxi%M;
    }
};