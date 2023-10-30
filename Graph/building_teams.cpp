#include <bits/stdc++.h>

using namespace std;

bool dfs(int node,int color, vector<int> &colors, vector<int> adj[]){

    colors[node] = color;

    for(int it : adj[node]){

        if ( colors[it] == 0){

            if( dfs(it, color ==1 ? 2 : 1 , colors, adj) == false) return false;

        } else if( colors[it] == colors[node]){

            return false;
        }
    }


    return true;

}

int main(){

    int n , m;

    cin >> n >> m;

    // make it a bipartite graph, and if it is not a bipartite graph return  impossible

    vector<int> adj[n+1];

    for(int i=0;i<m;i++){

        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> colors(n+1, 0);

    for(int i=1;i<=n;i++){

        if(colors[i] == 0){

            if( dfs(i,1, colors,adj) == false){

                cout << "IMPOSSIBLE" << "\n";

                return 0;
            }
        }
    }

    for(int i=1;i<=n;i++){

        cout << colors[i] << " ";
    }
}