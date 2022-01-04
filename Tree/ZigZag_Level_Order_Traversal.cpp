/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    bool even = true;
    vector<vector<int>> ans;
    while(!q.empty()) {
        
        int size = q.size();
        vector<int> level(size);
        for(int i=0; i<size; i++) {
            TreeNode* front = q.front();
            q.pop();
            if (even) level[i] = front->val;
            else level[size-i-1] = front->val;
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
        even = !even;
        ans.push_back(level);
    }
    return ans;
}
