vector<int> Solution::stepnum(int A, int B) {
    queue<int> q;
    vector<int> ans;
    vector<bool> visited(B+1, false);
    for(int i=0; i<10; i++) q.push(i);
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int front = q.front();
            q.pop();
            if (front < 0 || front > B) continue;
            if (visited[front]) continue;
            visited[front] = true;
            if (front >= A && front <= B) ans.push_back(front);
            int rem = front%10;
            if (rem > 0) q.push(front*10 + rem - 1);
            if (rem < 9) q.push(front*10 + rem + 1);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}