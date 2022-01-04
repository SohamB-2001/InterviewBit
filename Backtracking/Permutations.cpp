void solve(vector<int> A, int idx, vector<vector<int>> &ans) {
    if (idx >= A.size()) {
        ans.push_back(A);
        return;
    }
    for(int i=idx; i<A.size(); i++) {
        swap(A[idx], A[i]);
        solve(A, idx+1, ans);
        swap(A[idx], A[i]);
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    solve(A, 0, ans);
    return ans;
}
