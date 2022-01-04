bool isPalindrome(string A, int l, int r) {
    while(l < r) {
        if (A[l++] != A[r--]) return false;
    }
    return true;
}
void solve(string A, vector<string> &curr, int start, vector<vector<string>> &ans) {
    if (start >= A.size()) {
        ans.push_back(curr);
        return;
    }
    for(int i=start; i<A.size(); i++) {
        if (isPalindrome(A, start, i)) {
            curr.push_back(A.substr(start, i-start+1));
            solve(A, curr, i+1, ans);
            curr.pop_back();
        }
    }
}
vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> ans;
    vector<string> curr;
    solve(A, curr, 0, ans);
    return ans;
}

