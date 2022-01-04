int Solution::solve(vector<int> &A) {
    vector<int> odd(A.size(), 0), even(A.size(), 0);
    for(int i=A.size()-2; i>=0; i--) {
        if (i%2) {
            even[i] = A[i+1] + even[i+1];
            odd[i] = odd[i+1];
        }
        else {
            odd[i] = A[i+1] + odd[i+1];
            even[i] = even[i+1];
        }
    }
    int o = 0, e = 0, ans = 0;
    for(int i=0; i<A.size(); i++) {
        if (o + even[i] == e + odd[i]) ans++;
        if (i % 2 == 0) e += A[i];
        else o += A[i];
    }
    return ans;
}
