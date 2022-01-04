/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans;
int findDepth(TreeNode* A) {
    if (!A) return 0;
    int left = findDepth(A->left);
    int right = findDepth(A->right);
    if (abs(left-right) > 1) ans = 0;
    return 1 + max(left, right);
}
int Solution::isBalanced(TreeNode* A) {
    ans = 1;
    findDepth(A);
    return ans;
}
