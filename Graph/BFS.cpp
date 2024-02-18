#include <bits/stdc++.h>

using namespace std;


void BFS(int V,int E,vector<vector<int>> &G,int start) {
    queue<int> q;
    vector<bool> vis(V,false);
    q.push(start);
    vis[start] = true;
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        cout << temp << " ";

        for(int i = 0; i < G[temp].size();i++) {
            if(!vis[G[temp][i]]) {
                q.push(G[temp][i]);
                vis[G[temp][i]] = true;
            }
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
    BFS(V,E,G,start);
    return 0;
}
