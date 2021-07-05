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
ll dp[1001][3][4];
ll solve(ll date, ll late, ll absent) {
    if (late >= 2 || absent >= 3) {
        return 0;
    }
    if (date == n)return 1;
    if (dp[date][late][absent] != -1) {
        return dp[date][late][absent];
    }
    return dp[date][late][absent] = (solve(date + 1, late, 0) + solve(date + 1, late + 1, 0)
        + solve(date + 1, late, absent + 1)) % MOD;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    memset(dp, -1, sizeof(dp));
   cout<< solve(0, 0, 0);
}