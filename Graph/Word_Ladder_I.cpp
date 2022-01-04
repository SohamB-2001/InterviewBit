int Solution::solve(string A, string B, vector<string> &C) {
    unordered_set<string> dict;
    for(string s : C) dict.insert(s);
    queue<string> q;
    q.push(A);
    int depth = 1;
    while(!q.empty()) {
        int size = q.size();
        depth++;
        while(size--) {
            string curr = q.front();
            q.pop();
            for(int i=0; i<curr.size(); i++) {
                string temp = curr;
                for(int j=0; j<26; j++) {
                    temp[i] = 'a' + j;
                    if (temp == curr) continue;
                    if (temp == B) return depth;
                    if (dict.count(temp)) {
                        dict.erase(temp);
                        q.push(temp);
                    }
                }
            }    
        }
    }
    return 0; 
}
