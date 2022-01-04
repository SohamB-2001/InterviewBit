/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* search(TreeNode* A, int data) {
    TreeNode* curr = A;
    while(curr && curr->val != data) {
        if (curr->val < data) curr = curr->right;
        else curr = curr->left;
    }
    if (curr && curr->val == data) return curr;
    return NULL;
}
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode* node = search(A, B);
    if (node == NULL) return NULL;
    if (node->right) {
        TreeNode* curr = node->right;
        while(curr->left) curr = curr->left;
        return curr;
    }
    else {
        TreeNode* curr = A, *parent = NULL;
        while(curr != node) {
            if (curr->val > B) {
                parent = curr;
                curr = curr->left;
            }
            else curr = curr->right;
        }
        return parent;
    }
    return NULL;
}