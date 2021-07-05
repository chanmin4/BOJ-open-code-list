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
vector<vector<ll>>dp;
vector<ll>result;
ll solve(ll cnum,ll nnum){
    ll num;
    ll mini = 1e10;
    if (cnum <= 0)return 0;
    else if (result[cnum] > 0)return result[cnum];
    else {
        for (int i = 0; i < nnum; i++) {
            num = solve(cnum - dp[i][1], nnum) + dp[i][0];
            mini = min(mini, num);
        }
        result[cnum] = mini;
        return mini;
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> c >> n;
    dp = vector<vector<ll>>(n, vector<ll>(2));
    result = vector<ll>(c+1);
    for (int i = 0; i < n; i++) {
        cin >> dp[i][0] >> dp[i][1];
    }
    cout<<solve(c,n);
}