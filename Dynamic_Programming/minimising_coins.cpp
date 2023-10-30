#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(int n, int target,vector<int> &arr, vector<ll> &dp){

    if(target==0) return 0;

    if(dp[target]!=-1) return dp[target];

    ll miniCoins = 1e16;

    for(int i=0;i<n;i++){

        if(arr[i] <= target) miniCoins =  min(miniCoins,1 + solve(n, target-arr[i],arr, dp));
    }

    return dp[target] = miniCoins;
}

int main(){

    int n,x;
    cin >> n >> x;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    vector<ll> dp(x+1, -1);

    ll ans = solve(n, x, arr, dp) ;


    cout << (ans >= 1e16 ? -1 : ans) << "\n";


}