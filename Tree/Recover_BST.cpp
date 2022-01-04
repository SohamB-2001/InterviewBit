/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void storeInorder(TreeNode* A, vector<int> &inorder) {
    if (!A) return;
    storeInorder(A->left, inorder);
    inorder.push_back(A->val);
    storeInorder(A->right, inorder);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> inorder;
    storeInorder(A, inorder);
    for(int i=inorder.size()-1; i>0; i--) {
        if (inorder[i] < inorder[i-1]) {
            int j = 0;
            while(j<inorder.size()-1 && inorder[j+1] > inorder[j]) j++;
            return {inorder[i], inorder[j]};
        }
    }
    return {-1};
}
