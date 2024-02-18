#include <bits/stdc++.h>

using namespace std;

bool Bipartite(vector<vector<int>> &G,int start) {
    vector<int> colour(G.size(),-1);
    colour[start] = 1;
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        for(int i = 0; i < G[front].size();i++) {
            if(colour[G[front][i]] == -1) {
                colour[G[front][i]] = 1 - colour[front];
                q.push(G[front][i]);
            }
            else if(colour[G[front][i]] == colour[front]) return false;
        }
    }
    return true;
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
    bool ans = Bipartite(G,start);
    if(ans) cout << "Bipartite Graph" << endl;
    else cout << "Not Bipartite Graph" << endl;
    return 0;
}
