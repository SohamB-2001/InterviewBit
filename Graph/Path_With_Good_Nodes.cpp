int ans;
void dfs(vector<vector<int>> &graph, vector<int> &A, int curr, int count, int C, vector<bool> &visited) {
    visited[curr] = true;
    if (A[curr] == 1) count++;
    if (graph[curr].size() == 1) {
        if (count <= C) ans++;
        return;
    }
    for(int i : graph[curr]) {
        if (!visited[i]) dfs(graph, A, i, count, C, visited);
    }
}
int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    vector<vector<int>> graph(A.size());
    vector<bool> visited(A.size(), false);
    for(vector<int> v : B) {
        graph[v[0]-1].push_back(v[1]-1);
        graph[v[1]-1].push_back(v[0]-1);
    }
    ans = 0;
    dfs(graph, A, 0, 0, C, visited);
    return ans;
}
