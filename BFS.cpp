#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[999];
bool visited[999];

void bfs(queue<int> q){
  while(!q.empty()){
    int node = q.front();
    q.pop();
    if(!visited[node]){
      visited[node] = true;

      for(int i = 0; i < adj[node].size(); i++){
        if(!visited[adj[node][i]]){
          q.push(adj[node][i]);
        }
      }

      bfs(q);
    }
  }
}

int main() {
  int n;

  fstream file("input.txt");
  file >> n;

  for(int i = 0; i < n; i++){
    int node;
    int connection;

    file >> node;
    file >> connection;

    adj[node].push_back(connection);
  }

  queue<int> q;
  q.push(0);
  bfs(q);

  for(int i = 0; i < 7; i++){
    cout << i << ":" << visited[i] << " " << endl;
  }
}
