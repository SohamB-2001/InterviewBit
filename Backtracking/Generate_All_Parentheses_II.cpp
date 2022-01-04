void solve(int A, int open, int close, string curr, vector<string> &ans) {
    if (open == close && open == A) {
        ans.push_back(curr);
        return;
    }
    if (open < A) {
        curr += '(';
        solve(A, open+1, close, curr, ans);
        curr.pop_back();
    }
    if (open > close) {
        curr += ')';
        solve(A, open, close+1, curr, ans);
        curr.pop_back();
    }
}
vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    solve(A, 0, 0, "", ans);
    return ans;
}
