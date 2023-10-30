#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 1e9+7;

ll solve3(int n, int x,vector<int> &v){

    vector<ll> pre(x+1,0);
    vector<ll> curr(x+1,0);

    pre[0] = 1;

    for(int i=0;i<=x;i++) if((i%v[0]) == 0) pre[i] = 1;

    for(int i=1;i<n;i++){

        curr[0] = 1;

        for(int tar= 1;tar <= x;tar++){
            
            ll take = 0;

            if(v[i] <= tar) take = curr[tar-v[i]] %mod;

            ll notTake = pre[tar] % mod;

            curr[tar] = (take + notTake) % mod;


        }

        pre = curr;
    }

    return pre[x] % mod;
    
}

ll solve2(int n, int x, vector<int> &v){

    vector<vector<ll>> dp(n, vector<ll>(x+1,0));

    for(int i=0;i<n;i++) dp[i][0] = 1;

    for(int i=0;i<=x;i++) if((i%v[0]) == 0) dp[0][i] = 1;

    for(int i=1;i<n;i++){

        for(int tar= 1;tar <= x;tar++){
            
            ll take = 0;

            if(v[i] <= tar) take = dp[i][tar-v[i]] %mod;

            ll notTake = dp[i-1][tar] % mod;

            dp[i][tar] = (take + notTake) % mod;


        }
    }

    return dp[n-1][x] % mod;


}

ll solve(int index, int target, vector<int> &arr, vector<vector<ll>> &dp){

    if(target==0) return 1;
    if(index==0){

        if((target % arr[0]) == 0) return 1;

        return 0;
    }

    if(dp[index][target] !=-1) return dp[index][target];


    ll take = 0;

    if(arr[index] <= target) take = solve(index, target-arr[index], arr, dp) % mod;

    ll notTake = solve(index-1, target, arr, dp) % mod;

    return dp[index][target] = (take + notTake) % mod;
}

int main(){
    int n,x;

    cin >> n >> x;

    vector<int> v(n);

    for(int i=0;i<n;i++) cin >> v[i];

    // vector<vector<ll>> dp(n, vector<ll>(x+1,-1));


    // cout << solve(n-1,x,v, dp) << "\n"; 

    // cout << solve2(n, x, v);
    cout << solve3(n, x, v);
}