bool dfs(vector<string> &A, string B, int i, int j, int idx) {
    if (idx >= B.size()) return true;
    if (i < 0 || j < 0 || i >= A.size() || j >= A[0].size()) return false;
    if (A[i][j] != B[idx]) return false;
    return (dfs(A, B, i+1, j, idx+1) || dfs(A, B, i-1, j, idx+1) || dfs(A, B, i, j+1, idx+1) || dfs(A, B, i, j-1, idx+1));
}
int Solution::exist(vector<string> &A, string B) {
    for(int i=0; i<A.size(); i++) {
        for(int j=0; j<A[i].size(); j++) {
            if (A[i][j] == B[0]) {
                if(dfs(A, B, i, j, 0)) return 1;
            }
        }
    }
    return 0;
}