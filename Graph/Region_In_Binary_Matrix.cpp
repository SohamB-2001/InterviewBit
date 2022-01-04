int dfs(vector<vector<int>> &A, int i, int j) {
    if (i >= A.size() || j >= A[0].size() || i < 0 || j < 0) return 0;
    if (A[i][j] == 0) return 0;
    A[i][j] = 0;
    int ans = 1 + dfs(A, i+1, j) + dfs(A, i-1, j) + dfs(A, i, j+1) + dfs(A, i, j-1) + dfs(A, i+1, j+1) + dfs(A, i+1, j-1) + dfs(A, i-1, j+1) + dfs(A, i-1, j-1);
    // A[i][j] = 1;
    return ans;
}
int Solution::solve(vector<vector<int> > &A) {
    int ans = 0;
    for(int i=0; i<A.size(); i++) {
        for(int j=0; j<A[0].size(); j++) {
            if (A[i][j] == 1) {
                ans = max(ans, dfs(A, i, j));
            }
        }
    }
    return ans;
}
