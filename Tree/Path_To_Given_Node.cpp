/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool recurse(TreeNode* A, int B, vector<int> &path) {
    if (A == NULL) return false;
    path.push_back(A->val);
    if (A->val == B) return true;
    if (recurse(A->left, B, path) || recurse(A->right, B, path)) return true;
    path.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    recurse(A, B, ans);
    return ans;
}
