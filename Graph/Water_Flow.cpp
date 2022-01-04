void dfs(vector<vector<int>> &A, int i, int j, int prev, vector<vector<bool>> &vis) {
    if (i < 0 || j < 0 || i >= A.size() || j >= A[0].size()) return;
    if (vis[i][j]) return;
    if (A[i][j] < prev) return;
    vis[i][j] = true;
    dfs(A, i+1, j, A[i][j], vis);
    dfs(A, i-1, j, A[i][j], vis);
    dfs(A, i, j+1, A[i][j], vis);
    dfs(A, i, j-1, A[i][j], vis);
}
int Solution::solve(vector<vector<int> > &A) {
    vector<vector<bool>> blue(A.size(), vector<bool> (A[0].size(), 0));
    vector<vector<bool>> red(A.size(), vector<bool> (A[0].size(), 0));
    int ans = 0;
    for(int i=0; i<A.size(); i++) {
        dfs(A, i, 0, INT_MIN, blue);
        dfs(A, i, A[0].size()-1, INT_MIN, red);
    }
    for(int j=0; j<A[0].size(); j++) {
        dfs(A, 0, j, INT_MIN, blue);
        dfs(A, A.size()-1, j, INT_MIN, red);
    }
    for(int i=0; i<A.size(); i++) {
        for(int j=0; j<A[0].size(); j++) {
            if (red[i][j] && blue[i][j]) ans++;
        }
    }
    return ans;
}
