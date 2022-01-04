int Solution::solve(vector<int> &A, int B) {
    int sum = 0, ans = INT_MIN;
    for(int i=0; i<B; i++) sum += A[i];
    int i = B-1, j = A.size()-1;
    while(i>=0) {
        sum -= A[i--];
        sum += A[j--];
        ans = max(ans, sum);
    }
    return ans;
}
