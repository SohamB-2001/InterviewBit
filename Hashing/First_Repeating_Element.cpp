int Solution::solve(vector<int> &A) {
    unordered_map<int, int> mp;
    int minIdx = INT_MAX, ans = -1;
    for(int i=0; i<A.size(); i++) {
        if (mp.count(A[i])) {
            if (minIdx > mp[A[i]]) {
                minIdx = mp[A[i]];
                ans = A[i];
            }
        }
        else mp[A[i]] = i;
    }
    return ans;
}