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
    int cnt = 0;

    pair<int,int> solve(TreeNode *root){
        if (!root)
            return {0,0};
        
        auto [lsum, lcnt] = solve(root->left);
        auto [rsum, rcnt] = solve(root->right);
        
        int sum = lsum + rsum + root->val;
        int total = lcnt + rcnt + 1;

        if (root->val == sum / total)
            cnt++;
        
        return {sum, total};
    }

    int averageOfSubtree(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
            
        solve(root);
        return cnt;
    }
};