int Solution::minDistance(string A, string B) {
    vector<vector<int>> dp(A.length()+1, vector<int>(B.length()+1, 0));
    dp[0][0] = 0;
    for(int i=0; i<=A.length(); i++) dp[i][0] = i;
    for(int j=0; j<=B.length(); j++) dp[0][j] = j;
    for(int i=1; i<=A.length(); i++) {
        for(int j=1; j<=B.length(); j++) {
            if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    return dp.back().back();
}
