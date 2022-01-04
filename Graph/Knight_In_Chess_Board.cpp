vector<vector<int>> dirs = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(A+1, vector<bool>(B+1, false));
    q.push({C, D});
    int moves = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i == E && j == F) return moves;
            for(int k=0; k<dirs.size(); k++) {
                int x = i + dirs[k][0];
                int y = j + dirs[k][1];
                if (x > 0 && y > 0 && x <= A && y <= B && !visited[x][y]) {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        moves++;
    }
    return -1;
}
