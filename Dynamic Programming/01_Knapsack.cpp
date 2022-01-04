int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<vector<int>> dp(B.size()+1, vector<int> (C+1, 0));
    for(int i=1; i<=B.size(); i++) {
        for(int j=1; j<=C; j++) {
            if (j >= B[i-1]) {
                dp[i][j] = max(dp[i-1][j], A[i-1] + dp[i-1][j-B[i-1]]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp.back().back();
}
