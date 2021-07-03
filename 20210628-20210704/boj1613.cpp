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
    ll k;
    cin >> n >> k;
    vector<vector<ll>>dist(n + 1, vector<ll>(n + 1, 1e10));
    for (int i = 0; i < k; i++) {
        ll a, b;
        cin >> a >> b;
        dist[a][b] = 1;
    }
    for (int k = 1;k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll s;
    cin >> s;
    for(int i=0;i<s;i++){
        ll a, b;
        cin >> a >> b;
        if (dist[a][b] == 1e10 && dist[b][a] == 1e10)cout << 0 << "\n";
        else if (dist[a][b] == 1e10 && dist[b][a] != 1e10) {
            cout << 1 << "\n";//b가 먼저
        }
        else cout << -1 << "\n";
    }

}