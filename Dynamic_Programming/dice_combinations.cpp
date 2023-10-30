#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int mod = 1e9 + 7;

// ll solve3(ll target){

//     vector<ll> dp(target+1, 0);
//     dp[0] = 1;

//     for(ll tar=1;tar<=target;tar++){

//         ll count = 0;
//         for(ll i=1;i<=6 && tar-i>=0;i++){
//             count += dp[tar-i] %mod;
//         }

//         dp[tar] = count%mod;
//     }

//     return dp[target]%mod;
// }

ll solve2(ll target ){

    unordered_map<ll,ll> dp;

    dp[0] = 1;

    for(ll tar=1;tar<=target;tar++){

        ll count = 0;
        for(ll i=1;i<=6 && tar-i>=0;i++){

            count += dp[tar-i] %mod;

        }

        dp[tar] = count%mod;
    }

    return dp[target]%mod;
}

// ll solve(ll target, unordered_map<ll, ll> &dp){

//     // cout << target << endl;

//     if(target==0) return 1ll;

//     if(dp.count(target)){ 
//         return dp[target]%mod;
//     }

//     ll count = 0;

//     for(int i=1;i<=6 && target-i>=0;i++){
    
//         count += solve(target-i, dp)%mod;
//     }

//     return dp[target] = count %mod;
// }

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    // unordered_map<ll, ll> dp;

    

    cout << solve2(n);

    // cout << solve3(n);
}

