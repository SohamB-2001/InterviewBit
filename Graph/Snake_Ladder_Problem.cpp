nt Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    unordered_map<int, int> snakes, ladders;
    vector<bool> visited(101, false);
    for(int i=0; i<A.size(); i++) ladders[A[i][0]] = A[i][1];
    for(int i=0; i<B.size(); i++) snakes[B[i][0]] = B[i][1];
    queue<int> q;
    q.push(1);
    visited[1] = true;
    int rolls = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int curr = q.front();
            q.pop();
            if (curr == 100) return rolls;
            if (curr > 100) continue;
            for(int i=1; i<=6; i++) {
                int val = curr+i;
                if (!visited[val]) {
                    visited[val] = true;
                    if (ladders.count(val)) q.push(ladders[val]);
                    else if (snakes.count(val)) q.push(snakes[val]);
                    else q.push(val);
                }
            }
        }
        rolls++;
    }
    return -1;
}