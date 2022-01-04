/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* A, vector<int> &ans) {
    if (!A) return;
    TreeNode* t = A->left;
    stack<TreeNode*> s;
    s.push(A);
    while(!s.empty() || t) {
        while(t) {
            s.push(t);
            t = t->left;
        }
        TreeNode* top = s.top();
        s.pop();
        ans.push_back(top->val);
        s.push(top->right);
    }
}
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    inorder(A, ans);
    return ans;
}
