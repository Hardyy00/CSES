#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,ll>>> adj(n+1, vector<pair<int,ll>>());

    for(int i=0;i<m;i++){
        int u, v;
        ll w;

        cin >> u >> v >> w;

        adj[u].push_back({v,w});


    }

    priority_queue<pair<ll, int>> pq;

    vector<pair<ll, ll>> dis(n+1,{1e18, 0});

    dis[1].first = 0;
    pq.push({0,1});

    while(!pq.empty()){

        int node = pq.top().second;
        ll d = pq.top().first;

        pq.pop();

        for(auto it : adj[node]){
            int adjNode = it.first;
            ll adjDis = it.second;

            if(adjNode != n && d + adjDis < dis[adjNode].first){
                dis[adjNode].first = d + adjDis;
                dis[adjNode].second = max(dis[node].second , adjDis);
                pq.push({dis[adjNode].first, adjNode});
            }else if(adjNode == n){
                ll totDis = d + adjDis;
                ll maxPath = max(dis[node].second, adjDis);
                ll afterDiscount = totDis - maxPath + (maxPath/2);

                if(afterDiscount < dis[n].first){
                    dis[n].first = afterDiscount;
                }
            }

        }
    }

    cout << dis[n].first << "\n";

}