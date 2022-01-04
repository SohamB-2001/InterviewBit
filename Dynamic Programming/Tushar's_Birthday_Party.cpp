int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    long long ans = 0;
    long long maxAmount = *max_element(A.begin(), A.end());
    vector<vector<long long>> dp(B.size()+1, vector<long long>(maxAmount+1, 0));
    for(int i=1; i<=maxAmount; i++) dp[0][i] = INT_MAX;
    for(int i=1; i<=B.size(); i++) {
        for(int j=1; j<=maxAmount; j++) {
            if (j >= B[i-1]) {
                dp[i][j] = min(dp[i-1][j], C[i-1] + dp[i][j-B[i-1]]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    for(int i=0; i<A.size(); i++) {
        ans += dp[B.size()][A[i]];
    }
    return ans;
}
