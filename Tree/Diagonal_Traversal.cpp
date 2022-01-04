/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void store(TreeNode* A, int current, map<int, vector<int>> &mp) {
    if (!A) return;
    mp[current].push_back(A->val);
    store(A->left, current+1, mp);
    store(A->right, current, mp);
}
vector<int> Solution::solve(TreeNode* A) {
    map<int, vector<int>> mp;
    store(A, 0, mp);
    vector<int> ans;
    for(auto it : mp) {
        for(int i : it.second) ans.push_back(i);
    }
    return ans;
}
