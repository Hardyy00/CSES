#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 +7;

ll solve(int n, int target, vector<int> &arr, vector<ll> &dp){

    if(target==0) return 1;

    if(dp[target] !=-1) return dp[target];

    ll ways = 0;

    for(auto i : arr){

        if(i <= target) {

            ways = (ways  + solve(n, target-i, arr, dp)) % mod;
        }
    }

    return dp[target] = ways % mod;
}

int main(){

    int n, x;
    cin >>n >> x;

    vector<int> v(n);

    for(int i=0;i<n;i++)  cin >> v[i];

    vector<ll> dp(x+1, -1);

    cout << solve(n,x,v, dp) << "\n";

}