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
vector<ll>dp;
vector<ll>a;
ll solve(ll num) {
    if (num == 0)return 0;
    if (dp[num] != -1)return dp[num];
    dp[num] = 1e10;
    for (int i = 1; i < 1000; i++) {
        if (a[i] > num)break;
        dp[num] = min(dp[num], 1 + solve(num - a[i]));
    }
    return dp[num];
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    dp = vector<ll>(n + 1,-1);
    a = vector<ll>(1000);
    for (int i = 1; i < 1000; i++) {
        ll num = i * (i + 1) / 2;
        a[i] = a[i - 1] + num;
    }
    cout << solve(n);
}