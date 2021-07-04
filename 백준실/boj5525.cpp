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
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    string a;
    vector<ll>dp(m);
    cin >> a;
    for (int i = 2; i < m; i++) {
        if (a[i] == 'I' && a[i - 2] == 'I'&&a[i-1]=='O') {
            dp[i] = dp[i - 2] + 1;
        }
    }
    ll cnt = 0;
    for (int i = 0; i < m; i++) {
        if (dp[i] >= n) {
            cnt++;
        }
    }
    cout << cnt;
}