int Solution::solve(string A) {
    stack<char> s;
    int ans = 0;
    for(int i=0; i<A.size(); i++) {
        if (A[i] == '(') s.push(A[i]);
        else {
            if (!s.empty()) s.pop();
            else ans++;
        }
    }
    return s.size() + ans;
}
