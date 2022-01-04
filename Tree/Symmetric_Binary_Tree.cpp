/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode*A, TreeNode* B) {
    if (!A && !B) return 1;
    if (!A || !B) return 0;
    if (A->val != B->val) return 0;
    else return solve(A->left, B->right) && solve(A->right, B->left);
}
int Solution::isSymmetric(TreeNode* A) {
    return solve(A, A);
}