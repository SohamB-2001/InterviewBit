int Solution::numDecodings(string A) {
    if (A[0] == '0') return 0;
    vector<int> count(A.length()+1, 0);
    unsigned long int MOD = 1e9+7;
    count[0] = 1;
    count[1] = 1;
    for(int i=2; i<=A.length(); i++) {
        if (A[i-1] > '0') count[i] += count[i-1] % MOD;
        if ((A[i-2] == '1') || (A[i-2] == '2' && A[i-1] < '7')) count[i] += count[i-2] % MOD;
    }
    return count[A.length()] % MOD;
}
