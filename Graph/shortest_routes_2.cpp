#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){

    int n ,m,q;
    ll inf = 1e18;
    cin >> n >> m >> q;

    vector<vector<ll>> dp(n+1,vector<ll>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){

            dp[i][j] = dp[j][i] = inf;
        }

        dp[i][i] = 0;
    }

    for(int i=0;i<m;i++){

        int u, v;
        ll w;

        cin >> u >> v >> w;

        dp[u][v] = min(dp[u][v],w);
        dp[v][u] = min(dp[v][u], w);
    }

    for(int via=1;via<=n;via++){
        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++){

                if(i!=j){

                    if(dp[i][via] !=inf && dp[via][j] != inf){

                        dp[i][j] = min(dp[i][j], dp[i][via] + dp[via][j]);
                    }
                }
            }
        }
    }

    for(int i=0;i<q;i++){
        int u, v;
        cin >> u >> v;
        if(dp[u][v] == inf) cout << -1 << "\n";
        else cout << dp[u][v] << "\n";
    }
}