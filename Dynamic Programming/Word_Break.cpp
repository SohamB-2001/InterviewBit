bool dfs(string A, unordered_set<string> &dict, unordered_map<string, int> &dp) {
    if (dp.count(A)) return dp[A];
    for(int i=0; i<A.size(); i++) {
        string temp = A.substr(0, i+1);
        if (dict.count(temp)) {
            string rem = A.substr(i+1);
            if (!rem.length()) return dp[A] = 1;
            else if (dict.count(rem)) return dp[A] = 1;
            else if (dfs(rem, dict, dp)) return dp[A] = 1;
        }
    }
    return dp[A] = 0;
}
int Solution::wordBreak(string A, vector<string> &B) {
    unordered_set<string> dict;
    unordered_map<string, int> dp;
    for(string s : B) dict.insert(s);
    return dfs(A, dict, dp);
}
