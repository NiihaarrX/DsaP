//Also Known as Kahns algorithm


#include <bits/stdc++.h>

using namespace std;

vector<int> TopoSortBfs(vector<vector<int>> &G,vector<int> &indegree) {
        queue<int> q;
        vector<int> ans;
        int n = indegree.size();
        for(int i = 0; i < n;i++) {
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int temp = q.front();
            ans.push_back(temp);
            q.pop();
            for(int i = 0; i < G[temp].size();i++) {
                indegree[G[temp][i]]--;
                if(indegree[G[temp][i]] == 0) {
                    q.push(G[temp][i]);
                }
            }
        }
        return ans;
    }

    int main() {
        int V,E;
        cin >> V >> E;
        vector<vector<int>> G(V);
        vector<int> indegree(V,0);
        for(int i = 0; i < E;i++) {
            int a,b;
            cin >> a >> b;
            G[a].push_back(b);
            indegree[b]++;
        }
        vector<int> TopoSort = TopoSortBfs(G,indegree);
        if(TopoSort.size() != V) cout << "TopoSort Not Possible" << endl;
        else for (int i = 0; i < TopoSort.size(); i++) cout << TopoSort[i] << " ";
        cout << endl;
        return 0;
    }
