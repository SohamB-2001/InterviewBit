int Solution::solve(vector<int> &A) {
    int B = 0;
    for(int i : A) B += i;
    vector<vector<bool>> dp(A.size()+1, vector<bool> (B+1, false));
    for(int i=0; i<=A.size(); i++) dp[i][0] = true;
    for(int i=1; i<=A.size(); i++) {
        for(int j=1; j<=B; j++) {
            if (j >= A[i-1]) dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
            else dp[i][j] = dp[i-1][j];
        }
    }
    int diff = INT_MAX;
    for(int j=B/2; j>=0; j--) {
        if (dp[A.size()][j]) {
            diff = B - 2*j;
            break;
        }
    }
    return diff;
}
