/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int t2SumUtil(TreeNode* A, int B, unordered_set<int> &s) {
    if (A == NULL) return false;
    if (s.count(B-A->val)) return true;
    s.insert(A->val);
    if (B-A->val < A->val) return t2SumUtil(A->left, B, s);
    else return t2SumUtil(A->right, B, s);
}
int Solution::t2Sum(TreeNode* A, int B) {
    unordered_set<int> s;
    return t2SumUtil(A, B, s);
}
