int Solution::solve(vector<int> &A, int B) {
    vector<vector<bool>> dp(A.size()+1, vector<bool> (B+1, false));
    for(int i=0; i<=A.size(); i++) dp[i][0] = true;
    for(int i=1; i<=A.size(); i++) {
        for(int j=1; j<=B; j++) {
            if (j >= A[i-1]) dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp.back().back();
}
