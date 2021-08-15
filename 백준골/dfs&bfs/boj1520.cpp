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
ll n, t, m, k;
ll mx[4] = { 1,-1,0,0 };
ll my[4] = { 0,0,1,-1 };
vector<vector<ll>>mapp;
vector<vector<ll>>b;
ll dp(ll x, ll y) {
	if (x == 1 && y == 1) {
		return 1;
	}
	if (b[y][x] != -1) {
		return b[y][x];
	}
	b[y][x] = 0;
	for (int k = 0; k < 4; k++) {
		ll nextx = mx[k] + x;
		ll nexty = my[k] + y;
		if (1 <= nextx && nextx <= m && 1 <= nexty && nexty <= n) {
			if (mapp[nexty][nextx] > mapp[y][x]) {
				b[y][x] += dp(nextx, nexty);
			}
		}
	}
	return b[y][x];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	mapp=vector<vector<ll>>(n + 1, vector<ll>(m + 1));
	b=vector<vector<ll>>(n + 1, vector<ll>(m + 1, -1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mapp[i][j];
		}
	}
	cout << dp(m, n);

}