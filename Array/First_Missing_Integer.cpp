int Solution::firstMissingPositive(vector<int> &A) {
    int mx = A.size();
    for(int i=0; i<A.size(); i++) {
        if (A[i] <= 0 || A[i] > A.size()) A[i] = mx+1;
    }
    for(int i=0; i<A.size(); i++) {
        if (abs(A[i])-1 < A.size() && A[abs(A[i])-1] > 0) {
            A[abs(A[i])-1] *= -1;
        } 
    }
    for(int i=0; i<A.size(); i++) {
        if (A[i] > 0) return i+1;
    }
    return A.size()+1;
}
