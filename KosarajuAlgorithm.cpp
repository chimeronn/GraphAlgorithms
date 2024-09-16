#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Group and print out all strongly connected components using Kosaraju's Algorithm

int dfs(vector<vector<int>> adj, vector<bool>& vis, int curr, queue<int>& q) {
    vis[curr] = true;
    q.push(curr);
    for(int i : adj[curr]) {
        if(!vis[i]) {
            return dfs(adj, vis, i, q);
        }
    }
    return curr;
 }

 void rDfs(vector<vector<int>> rAdj, vector<bool>& vis, int curr, vector<int>& scc) {
    vis[curr] = true;
    scc.push_back(curr);
    for(int i : rAdj[curr]) {
        if(!vis[i]) rDfs(rAdj, vis, i, scc);
    }
 }

vector<vector<int>> kosaraju(vector<vector<int>> adj) {
    int size = adj.size();
    vector<bool> vis(size);
    queue<int> q;

    for(int i = 0; i < size; ++i) {
        if(!vis[i]) dfs(adj, vis, 0, q);
    }

    vector<vector<int>> rAdj(size);
    for(int i = 0; i < size; ++i) {
        for(int j : adj[i]) {
            rAdj[j].push_back(i);
        }
    }

    vector<bool> rVis(size);
    vector<vector<int>> stronglyConnectedCompenents;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if(rVis[curr]) continue;

        vector<int> scc = {};
        rDfs(rAdj, rVis, curr, scc);
        stronglyConnectedCompenents.push_back(scc);
    }
    return stronglyConnectedCompenents;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v);
    for(int i = 0; i < e; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
    }

    for(vector<int> scc : kosaraju(adj)) {
        for(int i : scc) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
