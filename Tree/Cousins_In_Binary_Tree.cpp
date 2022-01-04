/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    bool found = false;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        while(size--) {
            TreeNode* front = q.front();
            q.pop();
            if ((front->left && front->left->val == B) || (front->right && front->right->val == B)) found = true;
            else {
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }
        if (found) {
            vector<int> level;
            while(!q.empty()) {
                level.push_back(q.front()->val);
                q.pop();
            }
            return level;
        }
    }
    return {};
}
