int Solution::trap(const vector<int> &A) {
    vector<int> left(A.size(), 0), right(A.size(), 0);
    int ans = 0;
    for(int i=1; i<A.size(); i++) left[i] = max(A[i-1], left[i-1]);
    for(int i=A.size()-2; i>=0; i--) right[i] = max(A[i+1], right[i+1]);
    for(int i=0; i<A.size(); i++) {
        int area = min(left[i], right[i]) - A[i];
        if (area > 0) ans += area;
    }
    return ans;
}
