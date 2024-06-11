#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void topo_dfs(vector<vector<int>> &g,int src,vector<bool> &vis,stack<int> &st) {
  vis[src] = true;
  for(int &i : g[src]) {
    if(!vis[i]) topo_dfs(g,i,vis,st);
  }
  st.push(src);
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
  stack<int> st;
  topo_dfs(g,0,vis,st);
  while(!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
}
