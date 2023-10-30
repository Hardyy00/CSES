#include <bits/stdc++.h>

using namespace std;

void dfs(int node, bool visit[], vector<int> adj[]){

    visit[node] = true;

    for(auto it : adj[node]){

        if(visit[it] == false){

            dfs(it, visit, adj);
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n , m;
    cin >> n >> m;

    vector<int> adj[n+1];

    // we have to count the number of components and return components -1 

    for(int i=0;i<m;i++){

        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool visit[n+1] = {false};

    vector<pair<int,int>> ans;

    for(int i=1;i<=n;i++){

        if(visit[i] == false){

            dfs(i, visit, adj);

            if(i!=1){

                // since i-1 is a part of another component and i is a part of another component , a road can exist b/w i-1 and i
                ans.push_back({i-1,i});
                
            }
        }
    }

    cout << ans.size() << "\n";

    for(auto it : ans) cout << it.first << " " << it.second << "\n";

}