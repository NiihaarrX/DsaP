#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Kahn's Algorithm


void topo_bfs(vector<vector<int>> &g) {
  vector<int> indegree(g.size());
  queue<int> q;
  for(int i = 0;i < g.size();i++) for(auto j : g[i]) indegree[j]++;
  for(int i = 0;i < g.size();i++) if(!indegree[i]) q.push(i);
  while(!q.empty()) {
    int temp = q.front();
    cout << temp << " ";
    q.pop();
    for(int &i : g[temp]) {
      indegree[i]--;
      if(!indegree[i]) q.push(i);
    }
  }
}

int main() {
  int vertices = 9;
  // int edges = 8;
  vector<vector<int>> g(vertices);
  g[0] = {1, 2};
  g[1] = {3,6};
  g[2] = {4};
  g[3] = {7};
  g[4] = {};
  g[5] = {};
  g[6] = {8};
  g[7] = {};
  g[8] = {5};
  // int start = 0;
  vector<bool> vis(g.size(),false);
  topo_bfs(g);
  
}
