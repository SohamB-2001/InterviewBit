int Solution::minCut(string A) {
    if (A.length() == 1) return 0;
    vector<vector<bool>> dp(A.length(), vector<bool> (A.length(), 0));
    for(int i=0; i<A.length(); i++) dp[i][i] = true;
    for(int i=0; i < A.length()-1; i++) {
        if (A[i] == A[i+1]) dp[i][i+1] = true;
    }
    for(int len=3; len<=A.length(); len++) {
        for(int i=0; i<A.length()-len+1; i++) {
            int j = i+len-1;
            if (A[i] == A[j] && dp[i+1][j-1] == true) dp[i][j] = true;
        }
    }
    vector<int> minCuts(A.length(), INT_MAX);
    for(int i=0; i<A.length(); i++) {
        for(int j=i; j>=0; j--) {
            if (dp[j][i]) {
                if (j > 0) minCuts[i] = min(minCuts[i], 1 + minCuts[j-1]);
                else minCuts[i] = 0;
            }
        }
    }
    return minCuts.back() == INT_MAX ? 1 : minCuts.back();
}
