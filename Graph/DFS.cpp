#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<int>> &G,vector<bool> &vis,int start) {
    vis[start] = true;
    cout << start << " ";
    for(int i = 0;i < G[start].size();i++) {
        if(!vis[G[start][i]]) {
            DFS(G,vis,G[start][i]);
        }
    }
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
    vector<bool> vis(V,false);
    DFS(G,vis,start); 
}
