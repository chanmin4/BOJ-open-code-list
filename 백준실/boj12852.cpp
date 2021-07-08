#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<list>
#include<unordered_set>
#include<time.h>
#define fup(i,a,b,c) for(int i=a;i<=b;i+=c)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<ll, ll>P;
typedef pair<ld, ld>dP;
ll MOD = 1e6;
ll n, m, t, l, c;
vector<P>dp;
P solve(ll n) {
    if (n == 1){
        return P(0, 0);
    }
    if (dp[n].first != -1)return dp[n];
    ll mini1 = 1e10;
    ll mini2 = 1e10;
    ll mini3 = 1e10;
    if (n % 3 == 0) {
        mini1 = min(mini1, 1 + solve(n/3).first);
    }
    if (n % 2 == 0) {
        mini2 = min(mini2, 1 + solve(n / 2).first);
    }
    mini3 = min(mini3, 1 + solve(n - 1).first);
    ll checknum = min(mini1, min(mini2, mini3));
    if (checknum == mini1) {
        dp[n] = P(checknum, n/3);
    }
    else if (checknum == mini2) {
        dp[n] = P(checknum, n/2);
    }
    else {
        dp[n] = P(checknum, n - 1);
    }
    return dp[n];
}
bool comp(ll a, ll b) {
    return a > b;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    dp = vector<P>(n + 1,P(-1,0));
    cout << solve(n).first << "\n";
    ll temp = n;
    cout << n << " ";
    while (1) {
        if (temp == 1)break;
        cout << dp[temp].second<<" ";
        temp = dp[temp].second;
       
    }
}