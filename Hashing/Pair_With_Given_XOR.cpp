int Solution::solve(vector<int> &A, int B) {
    unordered_set<int> s;
    int ans = 0;
    for(int i=0; i<A.size(); i++) {
        // A ^ B = C -> C ^ B = A
        if (s.count(A[i]^B)) ans++;
        s.insert(A[i]);
    }
    return ans;
}
