#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<vector<int>> &g,int src,vector<bool> &vis) {
  cout << src << " ";
  vis[src] = true;
  for(int &i : g[src]) {
    if(!vis[i]) dfs(g,i,vis);
  }
}

int main() {
  int vertices = 9;
  // int edges = 10;
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
  vector<bool> vis(g.size(),false);
  dfs(g,start,vis);
  
}
