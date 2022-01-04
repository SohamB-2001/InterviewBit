int Solution::longestSubsequenceLength(const vector<int> &A) {
    vector<int> lis(A.size(), 1), lds(A.size(), 1);
    int ans = 0;
    for(int i=1; i<A.size(); i++) {
        for(int j=0; j<i; j++) {
            if (A[j] < A[i]) lis[i] = max(lis[i], 1+lis[j]);
        }
    }
    for(int i=A.size()-2; i>=0; i--) {
        for(int j=A.size()-1; j>i; j--) {
            if (A[j] < A[i]) lds[i] = max(lds[i], 1+lds[j]);
        }
    }
    for(int i=0; i<A.size(); i++) {
        ans = max(ans, lis[i]+lds[i]-1);
    }
    return ans;
}
