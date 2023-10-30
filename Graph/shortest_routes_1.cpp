#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
int main(){

    // TC: O(M * log N)
    // SC : O(N + M) + O(N)
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,ll>>> adj(n+1,vector<pair<int, ll>>());

    for(int i=0;i<m;i++){
        int u,v;
        ll w;

        cin >> u >> v >>w ;
 
        adj[u].push_back({v,w});
    }

    // min heap
    priority_queue<pair<ll,int> , vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    vector<ll> dis(n+1,1e18);

    dis[1] = 0;

    // distance , reached node
    pq.push({0, 1});

    while(!pq.empty()){

        int node = pq.top().second;
        ll d = pq.top().first;

        pq.pop();

        if(d > dis[node]) continue;

        for(auto it : adj[node]){

            int adjNode = it.first;
            ll adjDis = it.second;

            if(d + adjDis < dis[adjNode]){

                dis[adjNode] = d + adjDis;

                pq.push({dis[adjNode] , adjNode});
            }
        }
    }

    for(int i= 1; i<=n ;i++) cout << dis[i] << " " ;

    cout << "\n";


}