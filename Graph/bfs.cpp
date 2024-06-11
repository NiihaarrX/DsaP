#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &g,int edges,int src) {
  vector<bool> vis(g.size(),false);
  queue<int> q;
  q.push(src);
  vis[src] = true;
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    cout << top << " ";
    for(auto i : g[top]) {
      if(!vis[i]) q.push(i);
      vis[i] = true;
    }
  }
}

int main() {
  int vertices = 9;
  int edges = 10;
  vector<vector<int>> g(vertices);
  g[0] = {1, 2};
  g[1] = {0,3,6};
  g[2] = {0,4};
  g[3] = {1,7};
  g[4] = {2,5,7};
  g[5] = {4,8};
  g[6] = {1,8};
  g[7] = {3,4};
  g[8] = {5,6};
  int start = 0;
  bfs(g,edges,start);
  
}
int main() {
    int V,E,start;
    cin >> V >> E >> start;
    vector<vector<int>> G(V);
    for(int i = 0; i < E;i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    BFS(V,E,G,start);
    return 0;
}
