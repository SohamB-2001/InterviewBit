string Solution::solve(string A) {
    queue<char> q;
    unordered_map<char, int> mp;
    string ans;
    for(int i=0; i<A.size(); i++) {
        q.push(A[i]);
        mp[A[i]]++;
        while(!q.empty() && mp[q.front()] > 1) q.pop();
        if (q.empty()) ans += '#';
        else ans += q.front();
    }
    return ans;
}
