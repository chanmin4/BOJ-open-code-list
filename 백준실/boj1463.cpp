﻿#include<iostream>
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
vector<ll>dp;
ll solve(ll n) {
    if (n == 1)return 0;
    if (dp[n] != -1)return dp[n];
    ll mini = 1e10;
    if (n % 3 == 0) {
        mini= min(mini, 1 + solve(n / 3));
    }
    if (n % 2 == 0) {
        mini = min(mini, 1 + solve(n / 2));
    }
    mini = min(mini, 1 + solve(n - 1));
    return dp[n] = mini;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    dp=vector<ll>(n+1,-1);

    cout << solve(n);
}