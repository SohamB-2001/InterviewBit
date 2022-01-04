/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode* A, int &res) {
    if (!A) return 0;
    int l = solve(A->left, res);
    int r = solve(A->right, res);
    int temp = max(max(l, r) + A->val, A->val);
    int ans = max(temp, l + r + A->val);
    res = max(ans, res);
    return temp;
}
int Solution::maxPathSum(TreeNode* A) {
    int res = INT_MIN;
    solve(A, res);
    return res;
}
