int Solution::numDistinct(string A, string B) {
    vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
    for(int i=0; i<=A.size(); i++) dp[i][0] = 1;
    for(int i=1; i<=A.size(); i++) {
        for(int j=1; j<=B.size(); j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
            else dp[i][j] = dp[i-1][j];
        }
    } 
    return dp.back().back();
}
