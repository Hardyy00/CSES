#include <bits/stdc++.h>

using namespace std;

bool dfs(int node, int parent ,vector<int> &ans, vector<bool> &visit, vector<int> adj[]){

    visit[node] = true;
    ans.push_back(node);

    for(auto it : adj[node]){

        if(visit[it] == false){

            if( dfs( it, node, ans, visit, adj) ) return true;

        } else if( it != parent){

            ans.push_back(it);
            return true;
        }
    }

    ans.pop_back();
    return false;
}

int main(){

    int n, m;

    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i=0;i<m;i++){

        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    // bool visit[n+1]{false};
    vector<bool> visit(n+1, false);
    vector<int> ans;

    for(int i=1;i<=n;i++){

        if(visit[i] == false){

            if( dfs(i,-1, ans,visit, adj) ) break;
        }
    }

    if(ans.empty()) cout << "IMPOSSIBLE"<< "\n";


    else {


        int last = ans.back();

        int index = -1;

        for(int i=0;i<ans.size();i++){


            if(ans[i] == last) {
                index = i;
                break;
            }
        }

        cout << ans.size() - index << "\n" ;

        for(int i= index;i<ans.size();i++){

            cout << ans[i] << " ";
        }
    }
}