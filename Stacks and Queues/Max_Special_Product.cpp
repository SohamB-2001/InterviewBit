int Solution::maxSpecialProduct(vector<int> &A) {
    stack<int> s;
    long long int ans = 0;
    vector<int> left(A.size(), 0), right(A.size(), 0);
    for(int i=0; i<left.size(); i++) {
        while(!s.empty() && A[s.top()] <= A[i]) s.pop();
        if (!s.empty()) left[i] = s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i=right.size()-1; i>=0; i--) {
        while(!s.empty() && A[s.top()] <= A[i]) s.pop();
        if (!s.empty()) right[i] = s.top();
        s.push(i);
    }
    for(int i=1; i<A.size()-1; i++) {
        ans = max(ans, (long long)left[i]*right[i]);
    }
    return ans % (int)(1e9+7);
    // return ans
}