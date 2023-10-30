#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n , m;
    
    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i=0;i<m;i++){

        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    } 

    vector<int> dis(n+1, 1e8);
    vector<int> parent(n+1, -1);

    queue<int> q;

    dis[1] = 0;
    q.push(1);

    while(!q.empty()){

        int node = q.front();
        int d = dis[node];

        q.pop();

        for(auto it: adj[node]){

            if(d + 1 < dis[it]){

                dis[it] = d + 1;
                parent[it] = node;
                q.push(it);
            }

        }
    }

    if(dis[n] == 1e8){

        cout << "IMPOSSIBLE" << "\n";

        return 0;
    } 

    vector<int> ans;

    int node = n;

    while(node!=-1){
        ans.push_back(node);

        node = parent[node];
    }

    cout << dis[n] + 1 << "\n";

    for(int i=ans.size()-1 ; i>=0;i--){

        cout << ans[i] << " " ;
    }
}