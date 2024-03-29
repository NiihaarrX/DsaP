#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
   
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>dis(V,1e8);
        dis[S] = 0;
        for(int i=0;i<V-1;i++)
        {
            for(auto it: edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dis[u]!=1e8 && dis[u]+wt<dis[v])
                {
                    dis[v] = dis[u] + wt;
                }
            }
        }
        for(auto it : edges)
        {
            
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dis[u]!=1e8&& dis[u]+wt<dis[v])
                {
                    return {-1};
                }
        }
        return dis;
        
    }
};




int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}



