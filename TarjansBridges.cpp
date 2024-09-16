#include <iostream>
#include <vector>
using namespace std;

// Find critical edges in a graph using Tarjan's algorithm

void dfs(vector<vector<int>> adj, int curr, int time, vector<int>& disc, vector<int>& low, vector<int>& parent) {
    disc[curr - 1] = time;
    low[curr - 1] = time;
    for(int i : adj[curr - 1]) {
        int index = i - 1;
        if(disc[index] == -1) {
            parent[index] = curr;
            dfs(adj, i, time + 1, disc, low, parent);
        }
        if(i != parent[curr - 1]) low[curr - 1] = min(low[curr - 1], low[index]);
    }
    //cout << curr << " " << low[curr - 1] <<  " " << time << "\n";
}

vector<pair<int, int>> findBridges(vector<vector<int>> adj) {
    int size = adj.size();
    vector<int> disc(size, -1);
    vector<int> low(size, INT_MAX);
    vector<int> parent(size);
    vector<pair<int, int>> bridges;

    for(int i = 1; i < size + 1; ++i) {
        if(disc[i - 1] == -1) dfs(adj, i, 0, disc, low, parent);
    }

    for(int i = 1; i < size; ++i) {
       if(disc[i] == low[i]) bridges.push_back({parent[i], i + 1});
    }
    return bridges;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v);

    for(int i = 0; i < e; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1 - 1].push_back(v2);
        adj[v2 - 1].push_back(v1);
    }
    for(pair<int, int> bridge : findBridges(adj)) {
        cout << bridge.first << " " << bridge.second << "\n";
    }
}
