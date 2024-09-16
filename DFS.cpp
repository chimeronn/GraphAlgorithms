#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> adj[999];
bool visited[999];

void dfs(int node) {
  if(!visited[node]){
    visited[node] = true;

    for(int i = 0; i < adj[node].size(); i++){
      if(!visited[adj[node][i]]){
        dfs(adj[node][i]);
      }
    }

  }
}

int main() {
  fstream file ("input.txt");

  int n;
  file >> n;

  for(int i = 0; i < n; i++){
    int node;
    int connection;

    file >> node;
    file >> connection;

    adj[node].push_back(connection);
  }

  dfs(0);

  for(int i = 0; i < 7; i++){
    cout << i << ":" << visited[i] << " " << endl;
  }
}
