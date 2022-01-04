string Solution::simplifyPath(string A) {
    stack<string> s;
    int i = 0;
    string curr = "";
    while(i < A.size()) {
        if (A[i] == '/') {
            if (curr.length() == 0) i++;
            else {
                if (curr == "..") {
                    if (!s.empty()) s.pop();
                }
                else if (curr != ".") s.push(curr);
                curr = "";
                i++;
            }
        }
        else curr += A[i++];
    }
    if (curr.length() != 0) {
        if (curr == "..") {
            if (!s.empty()) s.pop();
        }
        else if (curr != ".") s.push(curr);
    }
    string ans;
    stack<string> s1;
    while(!s.empty()) {
        s1.push(s.top());
        s.pop();
    }
    while(!s1.empty()) {
        ans += '/';
        ans += s1.top();
        s1.pop();
    }
    return ans.length() == 0 ? "/" : ans;
}