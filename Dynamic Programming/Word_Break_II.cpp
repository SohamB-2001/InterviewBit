void dfs(string A, int idx, string curr, unordered_set<string> &dict, vector<string> &ans) {
    if (idx == A.size()) {
        curr.pop_back();
        ans.push_back(curr);
        return;
    }
    for(int i=idx; i<A.size(); i++) {
        string temp = A.substr(idx, i-idx+1);
        if (dict.count(temp)) {
            curr += temp + ' ';
            dfs(A, i+1, curr, dict, ans);
            curr.pop_back(); // removing space at the end
            int size = temp.size();
            while(size--) curr.pop_back();
        }
    }
}
vector<string> Solution::wordBreak(string A, vector<string> &B) {
    unordered_set<string> dict;
    vector<string> ans;
    for(string s : B) dict.insert(s);
    dfs(A, 0, "", dict, ans);
    return ans;
}
