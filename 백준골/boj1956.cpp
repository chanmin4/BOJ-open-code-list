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
typedef pair<ll, ll>P;
typedef pair<ld, ld>dP;
ll MOD = 1e6;
ll n, m, t, l;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll v, e;
    cin >> v >> e;
    vector<vector<ll>>dist(v + 1, vector<ll>(v + 1, 1e10));
    for (int i = 0; i < e; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            for (int k = 1; k <= v; k++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll mini = 1e10;
    for (int i = 1; i <= v; i++) {
        mini = min(dist[i][i], mini);
    }
    if (mini == 1e10)cout << -1;
    else {
        cout << mini;
    }
}