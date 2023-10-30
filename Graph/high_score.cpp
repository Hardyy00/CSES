#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){

    // we are required to find the maximum distance, and if the maximum distance is increasing infinitely 
    // then return -1

    // for that we know how to detect a negative loop cycle, hence converting all the +ve weights to -ve, and finding
    // the minimum distance.

    int n, m;
    cin >> n >> m;
    ll pinf = 1e17;
    ll ninf = -1e17;
    
    vector<vector<int>> edges(m, vector<int>(3));

    for(int i=0;i<m;i++){

        int u, v, w;
        cin >> u >> v >> w;

        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = -w;
    }

    // if(n==1) cout << 0 << endl;

    vector<ll> dis(n+1, pinf);
    dis[1] = 0;
    
    for(int i=0;i<n;i++){

        for(auto it : edges){

            int u = it[0];
            int v = it[1];
            ll w = (ll)it[2];

            if(dis[u] != pinf && dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                dis[v] = max(dis[v], ninf);  // limit the distance to -ve infinity
            }
        }

    }

    // another bellman ford algo, so that if because of loop all the node's value are decreasing , then changing them
    // to -ve infinity

    for(int i=0;i<n;i++){

        for(auto it : edges){

            int u = it[0];
            int v = it[1];
            ll w = (ll)it[2];

            if(dis[u] != pinf && dis[u] + w < dis[v]){
                dis[v] = ninf;  // if the value of the node, is decreasing , then changing it ot -ve infinity
            }
        }

    }

    // if th last node is unreachable ,then return -1, else print -ve of the distance, as we were to find the maximum distance 
    if(dis[n] == ninf || dis[n] == pinf) cout << -1 << "\n";
    else cout << -dis[n];



}