/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode*> q;
    q.push(A);
    while(!q.empty()) {
        int size = q.size();
        while(size > 1) {
            TreeLinkNode* front = q.front();
            q.pop();
            front->next = q.front();
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right); 
            size--;
        }
        TreeLinkNode* front = q.front();
        q.pop();
        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
    }
}
