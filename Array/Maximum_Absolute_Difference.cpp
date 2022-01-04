int Solution::maxArr(vector<int> &A) {
    // 4 forms
    // A[i] - A[j] + i - j -> A[i] + i - (A[j] + j)
    // A[j] - A[i] + i - j -> A[j] - j - (A[i] - i) 
    // A[i] - A[j] + j - i -> A[i] - i - (A[j] - j)
    // A[j] - A[i] + j - i -> A[j] + j - (A[i] + i)
    int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
    for(int i=0; i<A.size(); i++) {
        max1 = max(max1, A[i] + i);
        max2 = max(max2, A[i] - i);
        min1 = min(min1, A[i] + i);
        min2 = min(min2, A[i] - i);
    }
    return max(max1-min1, max2-min2);
}