/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    if (!A) return {};
    map<int, vector<int>> mp;
    queue<pair<TreeNode*, int>> q;
    q.push({A, 0});
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            pair<TreeNode*, int> front = q.front();
            q.pop();
            mp[front.second].push_back(front.first->val);
            if (front.first->left) q.push({front.first->left, front.second-1});
            if (front.first->right) q.push({front.first->right, front.second+1});
        }
    }
    vector<vector<int>> ans;
    for(auto it : mp) ans.push_back(it.second);
    return ans;
}
