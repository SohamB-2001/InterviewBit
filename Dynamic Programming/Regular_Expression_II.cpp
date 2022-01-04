int Solution::isMatch(const string A, const string B) {
    vector<vector<bool>> dp(A.length()+1, vector<bool>(B.length()+1, false));
    dp[0][0] = true;
    for(int i=1; i<=B.length(); i++) {
        if (B[i-1] == '*') dp[0][i] = dp[0][i-2];
    }
    for(int i=1; i<=A.length(); i++) {
        for(int j=1; j<=B.length(); j++) {
            if (B[j-1] == '.') dp[i][j] = dp[i-1][j-1];
            else if (B[j-1] == '*') {
                bool b1 = dp[i][j-2];
                bool b2 =  dp[i-1][j] && (A[i-1] == B[j-2] || B[j-2] == '.'); 
                dp[i][j] = b1 || b2;
            } 
            else if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1];
        }
    }
    return dp.back().back();
}
