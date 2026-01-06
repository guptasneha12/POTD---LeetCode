class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int reslevel = 0;
        int currlevel = 1;
        int maxi = INT_MIN;
        q.push(root);
        // USE BFS TRAVERSAL
        while (!q.empty()) {
            int n = q.size();
            int sum = 0;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (sum > maxi) {
                maxi = sum;
                reslevel = currlevel;
            }
            currlevel++;
        }
        return reslevel;
    }
};