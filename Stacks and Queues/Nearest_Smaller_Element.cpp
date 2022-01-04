vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    vector<int> ans(A.size());
    for(int i=0; i<A.size(); i++) {
        while(!s.empty() && s.top() >= A[i]) s.pop();
        if (s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        s.push(A[i]);
    }
    return ans;
}
