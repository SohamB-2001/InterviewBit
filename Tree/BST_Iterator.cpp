/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 stack<TreeNode*> s;
BSTIterator::BSTIterator(TreeNode *root) {
    TreeNode* curr = root;
    while(curr != NULL) {
        s.push(curr);
        curr = curr->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return s.size();
}

/** @return the next smallest number */
int BSTIterator::next() {
    int next = s.top()->val;
    TreeNode* curr = s.top()->right;
    s.pop();
    while(curr) {
        s.push(curr);
        curr = curr->left;
    }
    return next;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
